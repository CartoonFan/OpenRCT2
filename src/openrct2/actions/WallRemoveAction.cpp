/*****************************************************************************
 * Copyright (c) 2014-2020 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "WallRemoveAction.h"

#include "../Cheats.h"
#include "../OpenRCT2.h"
#include "../core/MemoryStream.h"
#include "../interface/Window.h"
#include "../localisation/StringIds.h"
#include "../management/Finance.h"
#include "../world/Location.hpp"
#include "../world/Wall.h"

WallRemoveAction::WallRemoveAction(const CoordsXYZD& loc)
    : _loc(loc)
{
}

void WallRemoveAction::AcceptParameters(GameActionParameterVisitor& visitor)
{
    visitor.Visit(_loc);
}

void WallRemoveAction::Serialise(DataSerialiser& stream)
{
    GameAction::Serialise(stream);

    stream << DS_TAG(_loc);
}

GameActions::Result::Ptr WallRemoveAction::Query() const
{
    GameActions::Result::Ptr res = std::make_unique<GameActions::Result>();
    res->Cost = 0;
    res->Expenditure = ExpenditureType::Landscaping;

    if (!LocationValid(_loc))
    {
        return std::make_unique<GameActions::Result>(
            GameActions::Status::InvalidParameters, STR_CANT_REMOVE_THIS, STR_INVALID_SELECTION_OF_OBJECTS);
    }

    const bool isGhost = GetFlags() & GAME_COMMAND_FLAG_GHOST;
    if (!isGhost && !(gScreenFlags & SCREEN_FLAGS_SCENARIO_EDITOR) && !gCheatsSandboxMode && !map_is_location_owned(_loc))
    {
        return std::make_unique<GameActions::Result>(
            GameActions::Status::NotOwned, STR_CANT_REMOVE_THIS, STR_LAND_NOT_OWNED_BY_PARK);
    }

    TileElement* wallElement = GetFirstWallElementAt(_loc, isGhost);
    if (wallElement == nullptr)
    {
        return std::make_unique<GameActions::Result>(
            GameActions::Status::InvalidParameters, STR_CANT_REMOVE_THIS, STR_INVALID_SELECTION_OF_OBJECTS);
    }

    res->Cost = 0;
    return res;
}

GameActions::Result::Ptr WallRemoveAction::Execute() const
{
    GameActions::Result::Ptr res = std::make_unique<GameActions::Result>();
    res->Cost = 0;
    res->Expenditure = ExpenditureType::Landscaping;

    const bool isGhost = GetFlags() & GAME_COMMAND_FLAG_GHOST;

    TileElement* wallElement = GetFirstWallElementAt(_loc, isGhost);
    if (wallElement == nullptr)
    {
        return std::make_unique<GameActions::Result>(
            GameActions::Status::InvalidParameters, STR_CANT_REMOVE_THIS, STR_INVALID_SELECTION_OF_OBJECTS);
    }

    res->Position.x = _loc.x + 16;
    res->Position.y = _loc.y + 16;
    res->Position.z = tile_element_height(res->Position);

    tile_element_remove_banner_entry(wallElement);
    map_invalidate_tile_zoom1({ _loc, wallElement->GetBaseZ(), (wallElement->GetBaseZ()) + 72 });
    tile_element_remove(wallElement);

    return res;
}

TileElement* WallRemoveAction::GetFirstWallElementAt(const CoordsXYZD& location, bool isGhost) const
{
    TileElement* tileElement = map_get_first_element_at(location);
    if (!tileElement)
        return nullptr;

    do
    {
        if (tileElement->GetType() != TILE_ELEMENT_TYPE_WALL)
            continue;
        if (tileElement->GetBaseZ() != location.z)
            continue;
        if (tileElement->GetDirection() != location.direction)
            continue;
        if (tileElement->IsGhost() != isGhost)
            continue;

        return tileElement;
    } while (!(tileElement++)->IsLastForTile());
    return nullptr;
}
