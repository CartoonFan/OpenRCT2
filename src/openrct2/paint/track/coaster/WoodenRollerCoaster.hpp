/*****************************************************************************
 * Copyright (c) 2014-2024 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include "../../../drawing/ImageId.hpp"
#include "../../../ride/TrackPaint.h"
#include "../../../world/Location.hpp"
#include "../../Boundbox.h"
#include "../../Paint.h"
#include "../../support/WoodenSupports.h"
#include "../../tile_element/Segment.h"
#include "../../track/Segment.h"

#include <cstdint>

static constexpr TunnelGroup kTunnelGroup = TunnelGroup::Square;

struct StraightWoodenTrack
{
    ImageIndex track;
    ImageIndex handrail;
    ImageIndex frontTrack = ImageIndexUndefined;
    ImageIndex frontHandrail = ImageIndexUndefined;
};

struct SpriteBoundBox2
{
    ImageIndex ImageIdA;
    ImageIndex ImageIdB;
    CoordsXYZ offset;
    ::BoundBoxXYZ BoundBox;
};

// Magic number 4 refers to the number of track blocks in a diagonal track element
static constexpr const WoodenSupportSubType WoodenRCDiagonalSupports[4][kNumOrthogonalDirections] = {
    { WoodenSupportSubType::Null, WoodenSupportSubType::Null, WoodenSupportSubType::Null,
      WoodenSupportSubType::Null }, // sequence 0
    { WoodenSupportSubType::Corner0, WoodenSupportSubType::Corner1, WoodenSupportSubType::Corner2,
      WoodenSupportSubType::Corner3 }, // sequence 1
    { WoodenSupportSubType::Corner2, WoodenSupportSubType::Corner3, WoodenSupportSubType::Corner0,
      WoodenSupportSubType::Corner1 }, // sequence 2
    { WoodenSupportSubType::Null, WoodenSupportSubType::Null, WoodenSupportSubType::Null,
      WoodenSupportSubType::Null } // sequence 3
};

template<bool isClassic>
ImageId WoodenRCGetTrackColour(const PaintSession& session)
{
    if (isClassic)
        return session.TrackColours;
    else
        return session.SupportColours;
}

ImageId WoodenRCGetRailsColour(PaintSession& session);

template<bool isClassic>
PaintStruct* WoodenRCTrackPaint(
    PaintSession& session, uint8_t direction, ImageIndex imageIdTrack, ImageIndex imageIdRails, const CoordsXYZ& offset,
    const BoundBoxXYZ& boundBox)
{
    ImageId imageId = WoodenRCGetTrackColour<isClassic>(session).WithIndex(imageIdTrack);
    ImageId railsImageId = WoodenRCGetRailsColour(session).WithIndex(imageIdRails);

    PaintAddImageAsParentRotated(session, direction, imageId, offset, boundBox);
    return PaintAddImageAsChildRotated(session, direction, railsImageId, offset, boundBox);
}

template<bool isClassic>
void WoodenRCTrackPaintBb(PaintSession& session, const SpriteBoundBox2* bb, int16_t height)
{
    if (bb->ImageIdA == 0)
        return;

    ImageId imageId = WoodenRCGetTrackColour<isClassic>(session).WithIndex(bb->ImageIdA);
    PaintAddImageAsParent(
        session, imageId, { bb->offset.x, bb->offset.y, height + bb->offset.z },
        { { bb->BoundBox.offset.x, bb->BoundBox.offset.y, height + bb->BoundBox.offset.z }, bb->BoundBox.length });
    if (bb->ImageIdB != 0)
    {
        ImageId railsImageId = WoodenRCGetRailsColour(session).WithIndex(bb->ImageIdB);
        PaintAddImageAsChild(
            session, railsImageId, { bb->offset.x, bb->offset.y, height + bb->offset.z },
            { { bb->BoundBox.offset, height + bb->BoundBox.offset.z }, bb->BoundBox.length });
    }
}

template<bool isClassic, std::array<StraightWoodenTrack, kNumOrthogonalDirections> imageIds>
static void WoodenRCTrackStraightBankTrack(PaintSession& session, uint8_t direction, int32_t height)
{
    WoodenRCTrackPaint<isClassic>(
        session, direction, imageIds[direction].track, imageIds[direction].handrail, { 0, 0, height },
        { { 0, 3, height }, { 32, 25, 2 } });
    if (imageIds[direction].frontTrack != ImageIndexUndefined)
    {
        WoodenRCTrackPaint<isClassic>(
            session, direction, imageIds[direction].frontTrack, imageIds[direction].frontHandrail, { 0, 0, height },
            { { 0, 26, height + 5 }, { 32, 1, 9 } });
    }
}

/** rct2: 0x008AC658, 0x008AC668, 0x008AC738 */
template<bool isClassic, std::array<StraightWoodenTrack, kNumOrthogonalDirections> imageIds>
void WoodenRCTrackFlatToBank(
    PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TrackElement& trackElement, SupportType supportType)
{
    WoodenRCTrackStraightBankTrack<isClassic, imageIds>(session, direction, height);
    WoodenASupportsPaintSetupRotated(
        session, supportType.wooden, WoodenSupportSubType::NeSw, direction, height, session.SupportColours);
    PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
    PaintUtilSetSegmentSupportHeight(session, kSegmentsAll, 0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + kDefaultGeneralSupportHeight);
}

/** rct2: 0x008AC6D8, 0x008AC6E8 */
template<bool isClassic, std::array<StraightWoodenTrack, kNumOrthogonalDirections> imageIds>
static void WoodenRCTrack25DegUpToBank(
    PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TrackElement& trackElement, SupportType supportType)
{
    WoodenRCTrackStraightBankTrack<isClassic, imageIds>(session, direction, height);
    WoodenASupportsPaintSetupRotated(
        session, supportType.wooden, WoodenSupportSubType::NeSw, direction, height, session.SupportColours,
        WoodenSupportTransitionType::Up25DegToFlat);
    if (direction == 0 || direction == 3)
    {
        PaintUtilPushTunnelRotated(session, direction, height - 8, kTunnelGroup, TunnelSubType::Flat);
    }
    else
    {
        PaintUtilPushTunnelRotated(session, direction, height + 8, kTunnelGroup, TunnelSubType::FlatTo25Deg);
    }
    PaintUtilSetSegmentSupportHeight(session, kSegmentsAll, 0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 40);
}

/** rct2: 0x008AC6B8, 0x008AC6C8 */
template<bool isClassic, std::array<StraightWoodenTrack, kNumOrthogonalDirections> imageIds>
static void WoodenRCTrackBankTo25DegUp(
    PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TrackElement& trackElement, SupportType supportType)
{
    WoodenRCTrackStraightBankTrack<isClassic, imageIds>(session, direction, height);
    WoodenASupportsPaintSetupRotated(
        session, supportType.wooden, WoodenSupportSubType::NeSw, direction, height, session.SupportColours,
        WoodenSupportTransitionType::FlatToUp25Deg);
    if (direction == 0 || direction == 3)
    {
        PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
    }
    else
    {
        PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::SlopeEnd);
    }
    PaintUtilSetSegmentSupportHeight(session, kSegmentsAll, 0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 48);
}

TRACK_PAINT_FUNCTION GetTrackPaintFunctionClassicWoodenRCFallback(OpenRCT2::TrackElemType trackType);
