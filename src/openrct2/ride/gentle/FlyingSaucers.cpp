/*****************************************************************************
 * Copyright (c) 2014-2024 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "../../interface/Viewport.h"
#include "../../object/StationObject.h"
#include "../../paint/Paint.h"
#include "../../paint/support/WoodenSupports.h"
#include "../Ride.h"
#include "../Track.h"
#include "../TrackPaint.h"

enum
{
    SprFlyingSaucersFloor = 21920,
    SprFlyingSaucersFenceNe = 21921,
    SprFlyingSaucersFenceSe = 21922,
    SprFlyingSaucersFenceSw = 21923,
    SprFlyingSaucersFenceNw = 21924,
};

static constexpr uint32_t FlyingSaucersFenceSprites[] = {
    SprFlyingSaucersFenceNe,
    SprFlyingSaucersFenceSe,
    SprFlyingSaucersFenceSw,
    SprFlyingSaucersFenceNw,
};

/**
 * rct2: 0x008873D8
 */
static void PaintFlyingSaucers(
    PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TrackElement& trackElement)
{
    uint8_t relativeTrackSequence = kTrackMap4x4[direction][trackSequence];

    int32_t edges = edges_4x4[relativeTrackSequence];

    WoodenASupportsPaintSetupRotated(
        session, WoodenSupportType::Truss, WoodenSupportSubType::NeSw, direction, height,
        GetStationColourScheme(session, trackElement));

    const StationObject* stationObject = ride.GetStationObject();

    if (stationObject != nullptr && !(stationObject->Flags & STATION_OBJECT_FLAGS::NO_PLATFORMS))
    {
        auto imageId = session.TrackColours.WithIndex(SprFlyingSaucersFloor);
        PaintAddImageAsParent(session, imageId, { 0, 0, height }, { { 1, 1, height }, { 30, 30, 1 } });
    }

    TrackPaintUtilPaintFences(
        session, edges, session.MapPosition, trackElement, ride, session.TrackColours, height, FlyingSaucersFenceSprites,
        session.CurrentRotation);

    PaintUtilSetSegmentSupportHeight(session, kSegmentsAll, 0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
}

/**
 * rct2: 0x00887208
 */
TRACK_PAINT_FUNCTION GetTrackPaintFunctionFlyingSaucers(int32_t trackType)
{
    if (trackType != TrackElemType::FlatTrack4x4)
    {
        return nullptr;
    }

    return PaintFlyingSaucers;
}
