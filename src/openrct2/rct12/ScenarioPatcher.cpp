/*****************************************************************************
 * Copyright (c) 2014-2024 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "ScenarioPatcher.h"

#include "../Context.h"
#include "../PlatformEnvironment.h"
#include "../core/File.h"
#include "../core/Guard.hpp"
#include "../core/Json.hpp"
#include "../core/Path.hpp"
#include "../ride/Track.h"
#include "../world/Location.hpp"
#include "../world/Map.h"
#include "../world/Surface.h"
#include "../world/tile_element/TileElementType.h"

#include <iostream>

static u8string ToOwnershipJsonKey(int ownershipType)
{
    switch (ownershipType)
    {
        case OWNERSHIP_UNOWNED:
            return "unowned";
        case OWNERSHIP_CONSTRUCTION_RIGHTS_OWNED:
            return "construction_rights_owned";
        case OWNERSHIP_OWNED:
            return "owned";
        case OWNERSHIP_CONSTRUCTION_RIGHTS_AVAILABLE:
            return "construction_rights_available";
        case OWNERSHIP_AVAILABLE:
            return "available";
    }
    Guard::Assert(0, "Unrecognized ownership type flag");
    return {};
}

static void ApplyLandOwnershipFixes(const json_t& landOwnershipFixes, int ownershipType)
{
    auto ownershipTypeKey = ToOwnershipJsonKey(ownershipType);
    if (!landOwnershipFixes.contains(ownershipTypeKey))
    {
        return;
    }

    auto ownershipParameters = landOwnershipFixes[ownershipTypeKey];
    constexpr u8string_view coordinatesKey = "coordinates";
    if (!ownershipParameters.contains(coordinatesKey))
    {
        Guard::Assert(0, "Cannot have ownership fix without coordinates array");
        return;
    }
    else if (!ownershipParameters[coordinatesKey].is_array())
    {
        Guard::Assert(0, "Ownership fix coordinates should be an array");
        return;
    }

    auto ownershipCoords = Json::AsArray(ownershipParameters[coordinatesKey]);
    if (ownershipCoords.empty())
    {
        Guard::Assert(0, "Ownership fix coordinates array should not be empty");
        return;
    }

    const bool cannotDowngrade = ownershipParameters.contains("cannot_downgrade")
        ? Json::GetBoolean(ownershipParameters["cannot_downgrade"], false)
        : false;
    std::initializer_list<TileCoordsXY> tiles;
    for (size_t i = 0; i < ownershipCoords.size(); ++i)
    {
        if (!ownershipCoords[i].is_array())
        {
            Guard::Assert(0, "Ownership fix coordinates should contain only arrays");
            return;
        }

        auto coordinatesPair = Json::AsArray(ownershipCoords[i]);
        if (coordinatesPair.size() != 2)
        {
            Guard::Assert(0, "Ownership fix coordinates sub array should have 2 elements");
            return;
        }
        FixLandOwnershipTilesWithOwnership(
            { { Json::GetNumber<int32_t>(coordinatesPair[0]), Json::GetNumber<int32_t>(coordinatesPair[1]) } }, ownershipType,
            cannotDowngrade);
    }
}

static void ApplyLandOwnershipFixes(const json_t& scenarioPatch)
{
    constexpr u8string_view landOwnershipKey = "land_ownership";
    if (!scenarioPatch.contains(landOwnershipKey))
    {
        return;
    }

    auto landOwnershipFixes = scenarioPatch[landOwnershipKey];
    for (const auto& ownershipType : { OWNERSHIP_UNOWNED, OWNERSHIP_CONSTRUCTION_RIGHTS_OWNED, OWNERSHIP_OWNED,
                                       OWNERSHIP_CONSTRUCTION_RIGHTS_AVAILABLE, OWNERSHIP_AVAILABLE })
    {
        ApplyLandOwnershipFixes(landOwnershipFixes, ownershipType);
    }
}

static void ApplyWaterFixes(const json_t& scenarioPatch)
{
    constexpr u8string_view waterFixKey = "water";
    if (!scenarioPatch.contains(waterFixKey))
    {
        return;
    }

    if (!scenarioPatch[waterFixKey].is_array())
    {
        Guard::Assert(0, "Water fix should be an array");
        return;
    }

    auto waterFixes = Json::AsArray(scenarioPatch[waterFixKey]);
    if (waterFixes.empty())
    {
        Guard::Assert(0, "Water fix array should not be empty");
        return;
    }

    for (size_t i = 0; i < waterFixes.size(); ++i)
    {
        constexpr u8string_view heightKey = "height";
        if (!waterFixes[i].contains(heightKey))
        {
            Guard::Assert(0, "Water fix sub-array should set a height");
            return;
        }

        auto waterHeight = waterFixes[i][heightKey];

        constexpr u8string_view coordinatesKey = "coordinates";
        if (!waterFixes[i].contains(coordinatesKey))
        {
            Guard::Assert(0, "Water fix sub-array should contain coordinates");
            return;
        }

        if (!waterFixes[i][coordinatesKey].is_array())
        {
            Guard::Assert(0, "Water fix coordinates sub-array should be an array");
            return;
        }

        auto coordinatesPairs = Json::AsArray(waterFixes[i][coordinatesKey]);
        if (coordinatesPairs.empty())
        {
            Guard::Assert(0, "Water fix coordinates sub-array should not be empty");
            return;
        }

        for (size_t j = 0; j < coordinatesPairs.size(); ++j)
        {
            if (!coordinatesPairs[j].is_array())
            {
                Guard::Assert(0, "Water fix coordinates should contain only arrays");
                return;
            }

            auto coordinatesPair = Json::AsArray(coordinatesPairs[j]);
            if (coordinatesPair.size() != 2)
            {
                Guard::Assert(0, "Water fix coordinates sub array should have 2 elements");
                return;
            }
            auto surfaceElement = MapGetSurfaceElementAt(
                TileCoordsXY{ Json::GetNumber<int32_t>(coordinatesPair[0]), Json::GetNumber<int32_t>(coordinatesPair[1]) });

            surfaceElement->SetWaterHeight(waterHeight);
        }
    }
}

static track_type_t toTrackType(const u8string_view trackTypeString)
{
    if (trackTypeString == "flat")
        return TrackElemType::Flat;
    else if (trackTypeString == "flat_covered")
        return TrackElemType::FlatCovered;
    else
    {
        Guard::Assert(0, "Unsupported track type conversion");
        return TrackElemType::None;
    }
}

static void ApplyTrackTypeFixes(const json_t& trackTilesFixes)
{
    constexpr u8string_view operationsKey = "operations";
    if (!trackTilesFixes.contains(operationsKey))
    {
        Guard::Assert(0, "Cannot apply track tile fixes when operations array is unset");
        return;
    }

    if (!trackTilesFixes[operationsKey].is_array())
    {
        Guard::Assert(0, "Track tile fixes should have an operations array");
        return;
    }

    auto fixOperations = Json::AsArray(trackTilesFixes[operationsKey]);
    if (fixOperations.empty())
    {
        Guard::Assert(0, "Operations fix array should not be empty");
        return;
    }

    for (size_t i = 0; i < fixOperations.size(); ++i)
    {
        constexpr u8string_view fromKey = "from";
        if (!fixOperations[i].contains(fromKey))
        {
            Guard::Assert(0, "Operation sub-array should contain a from key");
            return;
        }

        constexpr u8string_view toKey = "to";
        if (!fixOperations[i].contains(toKey))
        {
            Guard::Assert(0, "Operation sub-array should contain a to key");
            return;
        }

        auto fromTrackType = toTrackType(Json::GetString(fixOperations[i][fromKey]));
        auto destinationTrackType = toTrackType(Json::GetString(fixOperations[i][toKey]));

        constexpr u8string_view coordinatesKey = "coordinates";
        if (!fixOperations[i].contains(coordinatesKey))
        {
            Guard::Assert(0, "Operations fix sub-array should contain coordinates");
            return;
        }

        if (!fixOperations[i][coordinatesKey].is_array())
        {
            Guard::Assert(0, "Operations fix coordinates sub-array should be an array");
            return;
        }

        auto coordinatesPairs = Json::AsArray(fixOperations[i][coordinatesKey]);
        if (coordinatesPairs.empty())
        {
            Guard::Assert(0, "Operations fix coordinates sub-array should not be empty");
            return;
        }

        for (size_t j = 0; j < coordinatesPairs.size(); ++j)
        {
            if (!coordinatesPairs[j].is_array())
            {
                Guard::Assert(0, "Operations fix coordinates should contain only arrays");
                return;
            }

            auto coordinatesPair = Json::AsArray(coordinatesPairs[j]);
            if (coordinatesPair.size() != 2)
            {
                Guard::Assert(0, "Operations fix coordinates sub array should have 2 elements");
                return;
            }

            TileCoordsXY tile{ Json::GetNumber<int32_t>(coordinatesPair[0]), Json::GetNumber<int32_t>(coordinatesPair[1]) };
            auto* tileElement = MapGetFirstElementAt(tile);
            if (tileElement == nullptr)
                continue;

            do
            {
                if (tileElement->GetType() != TileElementType::Track)
                    continue;

                auto* trackElement = tileElement->AsTrack();
                if (trackElement->GetTrackType() != fromTrackType)
                    continue;

                trackElement->SetTrackType(destinationTrackType);
            } while (!(tileElement++)->IsLastForTile());
        }
    }
}

static TileElementType toTileElementType(const u8string_view tileTypeString)
{
    if (tileTypeString == "track")
        return TileElementType::Track;
    else
    {
        Guard::Assert(0, "Unsupported tile type conversion");
        return TileElementType::Track;
    }
}

static void ApplyTileFixes(const json_t& scenarioPatch)
{
    constexpr u8string_view tilesKey = "tiles";
    if (!scenarioPatch.contains(tilesKey))
    {
        return;
    }

    auto tilesFixes = scenarioPatch[tilesKey];
    constexpr u8string_view typeKey = "type";
    if (!tilesFixes.contains(typeKey))
    {
        Guard::Assert(0, "Cannot apply tile fixes without defined type");
    }
    else
    {
        auto tileType = toTileElementType(Json::GetString(tilesFixes[typeKey]));
        if (tileType == TileElementType::Track)
        {
            ApplyTrackTypeFixes(tilesFixes);
        }
    }
}

static u8string GetPatchFileName(u8string_view scenarioName)
{
    auto env = OpenRCT2::GetContext()->GetPlatformEnvironment();
    auto scenarioPatches = env->GetDirectoryPath(OpenRCT2::DIRBASE::OPENRCT2, OpenRCT2::DIRID::SCENARIO_PATCHES);
    auto scenarioPatchFile = Path::WithExtension(Path::GetFileNameWithoutExtension(scenarioName), ".json");
    return Path::Combine(scenarioPatches, scenarioPatchFile);
}

void RCT12::FetchAndApplyScenarioPatch(u8string_view scenarioName, bool isScenario)
{
    auto patchPath = GetPatchFileName(scenarioName);
    std::cout << "Path is: " << patchPath << std::endl;
    // TODO: Check if case sensitive, some scenario names have all lowercase variations
    if (File::Exists(patchPath))
    {
        auto scenarioPatch = Json::ReadFromFile(patchPath);
        // TODO: Land ownership is applied even when loading saved scenario. Should it?
        ApplyLandOwnershipFixes(scenarioPatch);
        if (isScenario)
        {
            ApplyWaterFixes(scenarioPatch);
            ApplyTileFixes(scenarioPatch);
        }
    }
}
