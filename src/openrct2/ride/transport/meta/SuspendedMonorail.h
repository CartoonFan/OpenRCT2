/*****************************************************************************
 * Copyright (c) 2014-2023 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include "../../../sprites.h"
#include "../../RideData.h"
#include "../../ShopItem.h"
#include "../../Track.h"

// clang-format off
constexpr RideTypeDescriptor SuspendedMonorailRTD =
{
    SET_FIELD(AlternateType, RIDE_TYPE_NULL),
    SET_FIELD(Category, RIDE_CATEGORY_TRANSPORT),
    SET_FIELD(EnabledTrackPieces, {TRACK_STRAIGHT, TRACK_STATION_END, TRACK_SLOPE, TRACK_S_BEND, TRACK_CURVE_SMALL, TRACK_CURVE, TRACK_CURVE_LARGE}),
    SET_FIELD(ExtraTrackPieces, {}),
    SET_FIELD(CoveredTrackPieces, {}),
    SET_FIELD(StartTrackPiece, TrackElemType::EndStation),
    SET_FIELD(TrackPaintFunction, GetTrackPaintFunctionSuspendedMonorail),
    SET_FIELD(Flags, RIDE_TYPE_FLAGS_TRACK_HAS_3_COLOURS | RIDE_TYPE_FLAG_CAN_SYNCHRONISE_ADJACENT_STATIONS |
                     RIDE_TYPE_FLAG_HAS_LEAVE_WHEN_ANOTHER_VEHICLE_ARRIVES_AT_STATION |
                     RIDE_TYPE_FLAG_HAS_DATA_LOGGING | RIDE_TYPE_FLAG_HAS_LOAD_OPTIONS | RIDE_TYPE_FLAG_HAS_VEHICLE_COLOURS |
                     RIDE_TYPE_FLAG_HAS_TRACK | RIDE_TYPE_FLAG_SUPPORTS_MULTIPLE_TRACK_COLOUR |
                     RIDE_TYPE_FLAG_ALLOW_MUSIC | RIDE_TYPE_FLAG_HAS_ENTRANCE_EXIT | RIDE_TYPE_FLAG_ALLOW_MORE_VEHICLES_THAN_STATION_FITS |
                     RIDE_TYPE_FLAG_ALLOW_MULTIPLE_CIRCUITS | RIDE_TYPE_FLAG_TRANSPORT_RIDE | RIDE_TYPE_FLAG_SHOW_IN_TRACK_DESIGNER |
                     RIDE_TYPE_FLAG_IS_SUSPENDED),
    SET_FIELD(RideModes, EnumsToFlags(RideMode::ContinuousCircuit, RideMode::Shuttle)),
    SET_FIELD(DefaultMode, RideMode::ContinuousCircuit),
    SET_FIELD(OperatingSettings, { 0, 0, 0, 0, 0, 0 }),
    SET_FIELD(Naming, { STR_RIDE_NAME_SUSPENDED_MONORAIL, STR_RIDE_DESCRIPTION_SUSPENDED_MONORAIL }),
    SET_FIELD(NameConvention, { RideComponentType::Train, RideComponentType::Track, RideComponentType::Station }),
    SET_FIELD(EnumName, nameof(RIDE_TYPE_SUSPENDED_MONORAIL)),
    SET_FIELD(AvailableBreakdowns, (1 << BREAKDOWN_SAFETY_CUT_OUT) | (1 << BREAKDOWN_DOORS_STUCK_CLOSED) | (1 << BREAKDOWN_DOORS_STUCK_OPEN) | (1 << BREAKDOWN_VEHICLE_MALFUNCTION)),
    SET_FIELD(Heights, { 12, 40, 32, 8, }),
    SET_FIELD(MaxMass, 78),
    SET_FIELD(LiftData, { OpenRCT2::Audio::SoundId::Null, 5, 5 }),
    SET_FIELD(RatingsMultipliers, { 70, 6, -10 }),
    SET_FIELD(UpkeepCosts, { 70, 20, 0, 10, 3, 10 }),
    SET_FIELD(BuildCosts, { 32.50_GBP, 2.50_GBP, 50, }),
    SET_FIELD(DefaultPrices, { 10, 0 }),
    SET_FIELD(DefaultMusic, MUSIC_OBJECT_SUMMER),
    SET_FIELD(PhotoItem, ShopItem::Photo),
    SET_FIELD(BonusValue, 60),
    SET_FIELD(ColourPresets, TRACK_COLOUR_PRESETS(
        { COLOUR_BORDEAUX_RED, COLOUR_BLACK, COLOUR_BLACK },
        { COLOUR_DARK_PURPLE, COLOUR_DARK_PURPLE, COLOUR_BLACK },
        { COLOUR_DARK_GREEN, COLOUR_DARK_GREEN, COLOUR_BLACK },
    )),
    SET_FIELD(ColourPreview, { SPR_RIDE_DESIGN_PREVIEW_SUSPENDED_MONORAIL_TRACK, SPR_RIDE_DESIGN_PREVIEW_SUSPENDED_MONORAIL_SUPPORTS }),
    SET_FIELD(ColourKey, RideColourKey::Ride),
    SET_FIELD(Name, "suspended_monorail"),
    SET_FIELD(RatingsData,
    {
        RatingsCalculationType::Normal,
        { RIDE_RATING(2, 15), RIDE_RATING(0, 23), RIDE_RATING(0, 8) },
        14,
        -1,
        false,
        {
            { RatingsModifierType::BonusLength,            6000,             764, 0, 0 },
            { RatingsModifierType::BonusTrainLength,       0,                93622, 0, 0 },
            { RatingsModifierType::BonusMaxSpeed,          0,                44281, 70849, 35424 },
            { RatingsModifierType::BonusAverageSpeed,      0,                291271, 218453, 0 },
            { RatingsModifierType::BonusDuration,          150,              21845, 0, 0 },
            { RatingsModifierType::BonusSheltered,         0,                5140, 6553, 18724 },
            { RatingsModifierType::BonusProximity,         0,                12525, 0, 0 },
            { RatingsModifierType::BonusScenery,           0,                25098, 0, 0 },
            { RatingsModifierType::RequirementLength,      0xAA0000,         2, 2, 2 },
            { RatingsModifierType::RequirementUnsheltered, 4,                4, 1, 1 },
        },
    }),
};
// clang-format on
