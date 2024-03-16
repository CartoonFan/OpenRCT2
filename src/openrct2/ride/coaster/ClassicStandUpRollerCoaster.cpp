/*****************************************************************************
 * Copyright (c) 2014-2024 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "../Track.h"
#include "../TrackPaint.h"
#include "../../sprites.h"

#include <cstdint>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-const-variable"

static constexpr ImageIndex kClassicStandUpRcFlatToRightBank0 = SPR_CSG_BEGIN + 67009;
static constexpr ImageIndex kClassicStandUpRcFlatToLeftBank2 = SPR_CSG_BEGIN + 67010;
static constexpr ImageIndex kClassicStandUpRcFlatToLeftBank0 = SPR_CSG_BEGIN + 67011;
static constexpr ImageIndex kClassicStandUpRcFlatToRightBank2 = SPR_CSG_BEGIN + 67012;
static constexpr ImageIndex kClassicStandUpRcFlatToLeftBank3 = SPR_CSG_BEGIN + 67013;
static constexpr ImageIndex kClassicStandUpRcFlatToRightBank1 = SPR_CSG_BEGIN + 67014;
static constexpr ImageIndex kClassicStandUpRcFlatToRightBank3 = SPR_CSG_BEGIN + 67015;
static constexpr ImageIndex kClassicStandUpRcFlatToLeftBank1 = SPR_CSG_BEGIN + 67016;
static constexpr ImageIndex kClassicStandUpRcRightTurn5TilesBanked0_0 = SPR_CSG_BEGIN + 67017;
static constexpr ImageIndex kClassicStandUpRcRightTurn5TilesBanked0_1 = SPR_CSG_BEGIN + 67018;
static constexpr ImageIndex kClassicStandUpRcRightTurn5TilesBanked0_2 = SPR_CSG_BEGIN + 67019;
static constexpr ImageIndex kClassicStandUpRcRightTurn5TilesBanked0_3 = SPR_CSG_BEGIN + 67020;
static constexpr ImageIndex kClassicStandUpRcRightTurn5TilesBanked0_4 = SPR_CSG_BEGIN + 67021;
static constexpr ImageIndex kClassicStandUpRcRightTurn5TilesBanked1_0 = SPR_CSG_BEGIN + 67022;
static constexpr ImageIndex kClassicStandUpRcRightTurn5TilesBanked1_1 = SPR_CSG_BEGIN + 67023;
static constexpr ImageIndex kClassicStandUpRcRightTurn5TilesBanked1_2 = SPR_CSG_BEGIN + 67024;
static constexpr ImageIndex kClassicStandUpRcRightTurn5TilesBanked1_3 = SPR_CSG_BEGIN + 67025;
static constexpr ImageIndex kClassicStandUpRcRightTurn5TilesBanked1_4 = SPR_CSG_BEGIN + 67026;
static constexpr ImageIndex kClassicStandUpRcRightTurn5TilesBanked2_0 = SPR_CSG_BEGIN + 67027;
static constexpr ImageIndex kClassicStandUpRcRightTurn5TilesBanked2_1 = SPR_CSG_BEGIN + 67028;
static constexpr ImageIndex kClassicStandUpRcRightTurn5TilesBanked2_2 = SPR_CSG_BEGIN + 67029;
static constexpr ImageIndex kClassicStandUpRcRightTurn5TilesBanked2_3 = SPR_CSG_BEGIN + 67030;
static constexpr ImageIndex kClassicStandUpRcRightTurn5TilesBanked2_4 = SPR_CSG_BEGIN + 67031;
static constexpr ImageIndex kClassicStandUpRcRightTurn5TilesBanked3_0 = SPR_CSG_BEGIN + 67032;
static constexpr ImageIndex kClassicStandUpRcRightTurn5TilesBanked3_1 = SPR_CSG_BEGIN + 67033;
static constexpr ImageIndex kClassicStandUpRcRightTurn5TilesBanked3_2 = SPR_CSG_BEGIN + 67034;
static constexpr ImageIndex kClassicStandUpRcRightTurn5TilesBanked3_3 = SPR_CSG_BEGIN + 67035;
static constexpr ImageIndex kClassicStandUpRcRightTurn5TilesBanked3_4 = SPR_CSG_BEGIN + 67036;
static constexpr ImageIndex kClassicStandUpRc25DegUpToFlatRightBanked0 = SPR_CSG_BEGIN + 67037;
static constexpr ImageIndex kClassicStandUpRc25DegUpToFlatRightBanked1 = SPR_CSG_BEGIN + 67038;
static constexpr ImageIndex kClassicStandUpRc25DegUpToFlatRightBanked2 = SPR_CSG_BEGIN + 67039;
static constexpr ImageIndex kClassicStandUpRc25DegUpToFlatRightBanked3 = SPR_CSG_BEGIN + 67040;
static constexpr ImageIndex kClassicStandUpRc25DegUpToFlatLeftBanked0 = SPR_CSG_BEGIN + 67041;
static constexpr ImageIndex kClassicStandUpRc25DegUpToFlatLeftBanked1 = SPR_CSG_BEGIN + 67042;
static constexpr ImageIndex kClassicStandUpRc25DegUpToFlatLeftBanked2 = SPR_CSG_BEGIN + 67043;
static constexpr ImageIndex kClassicStandUpRc25DegUpToFlatLeftBanked3 = SPR_CSG_BEGIN + 67044;
static constexpr ImageIndex kClassicStandUpRcLeftBankedTo25DegUp0 = SPR_CSG_BEGIN + 67045;
static constexpr ImageIndex kClassicStandUpRcLeftBankedTo25DegUp1 = SPR_CSG_BEGIN + 67046;
static constexpr ImageIndex kClassicStandUpRcLeftBankedTo25DegUp2 = SPR_CSG_BEGIN + 67047;
static constexpr ImageIndex kClassicStandUpRcLeftBankedTo25DegUp3 = SPR_CSG_BEGIN + 67048;
static constexpr ImageIndex kClassicStandUpRcRightBankedTo25DegUp0 = SPR_CSG_BEGIN + 67049;
static constexpr ImageIndex kClassicStandUpRcRightBankedTo25DegUp1 = SPR_CSG_BEGIN + 67050;
static constexpr ImageIndex kClassicStandUpRcRightBankedTo25DegUp2 = SPR_CSG_BEGIN + 67051;
static constexpr ImageIndex kClassicStandUpRcRightBankedTo25DegUp3 = SPR_CSG_BEGIN + 67052;
static constexpr ImageIndex kClassicStandUpRcLeftBanked0 = SPR_CSG_BEGIN + 67053;
static constexpr ImageIndex kClassicStandUpRcLeftBanked1 = SPR_CSG_BEGIN + 67054;
static constexpr ImageIndex kClassicStandUpRcLeftBanked2 = SPR_CSG_BEGIN + 67055;
static constexpr ImageIndex kClassicStandUpRcLeftBanked3 = SPR_CSG_BEGIN + 67056;

static constexpr ImageIndex kClassicStandUpRcRightTurn3TilesBanked0_0 = SPR_CSG_BEGIN + 67229;
static constexpr ImageIndex kClassicStandUpRcRightTurn3TilesBanked0_1 = SPR_CSG_BEGIN + 67230;
static constexpr ImageIndex kClassicStandUpRcRightTurn3TilesBanked0_2 = SPR_CSG_BEGIN + 67231;
static constexpr ImageIndex kClassicStandUpRcRightTurn3TilesBanked1_0 = SPR_CSG_BEGIN + 67232;
static constexpr ImageIndex kClassicStandUpRcRightTurn3TilesBanked1_1 = SPR_CSG_BEGIN + 67233;
static constexpr ImageIndex kClassicStandUpRcRightTurn3TilesBanked1_2 = SPR_CSG_BEGIN + 67234;
static constexpr ImageIndex kClassicStandUpRcRightTurn3TilesBanked2_0 = SPR_CSG_BEGIN + 67235;
static constexpr ImageIndex kClassicStandUpRcRightTurn3TilesBanked2_1 = SPR_CSG_BEGIN + 67236;
static constexpr ImageIndex kClassicStandUpRcRightTurn3TilesBanked2_2 = SPR_CSG_BEGIN + 67237;
static constexpr ImageIndex kClassicStandUpRcRightTurn3TilesBanked3_0 = SPR_CSG_BEGIN + 67238;
static constexpr ImageIndex kClassicStandUpRcRightTurn3TilesBanked3_1 = SPR_CSG_BEGIN + 67239;
static constexpr ImageIndex kClassicStandUpRcRightTurn3TilesBanked3_2 = SPR_CSG_BEGIN + 67240;

static constexpr ImageIndex kClassicStandUpRcRightBankedOrthogonalToDiag0_0 = SPR_CSG_BEGIN + 67361;
static constexpr ImageIndex kClassicStandUpRcRightBankedOrthogonalToDiag0_1 = SPR_CSG_BEGIN + 67362;
static constexpr ImageIndex kClassicStandUpRcRightBankedOrthogonalToDiag0_2 = SPR_CSG_BEGIN + 67363;
static constexpr ImageIndex kClassicStandUpRcRightBankedOrthogonalToDiag0_3 = SPR_CSG_BEGIN + 67364;
static constexpr ImageIndex kClassicStandUpRcRightBankedOrthogonalToDiag1_0 = SPR_CSG_BEGIN + 67365;
static constexpr ImageIndex kClassicStandUpRcRightBankedOrthogonalToDiag1_1 = SPR_CSG_BEGIN + 67366;
static constexpr ImageIndex kClassicStandUpRcRightBankedOrthogonalToDiag1_2 = SPR_CSG_BEGIN + 67367;
static constexpr ImageIndex kClassicStandUpRcRightBankedOrthogonalToDiag1_3 = SPR_CSG_BEGIN + 67368;
static constexpr ImageIndex kClassicStandUpRcRightBankedOrthogonalToDiag2_0 = SPR_CSG_BEGIN + 67369;
static constexpr ImageIndex kClassicStandUpRcRightBankedOrthogonalToDiag2_1 = SPR_CSG_BEGIN + 67370;
static constexpr ImageIndex kClassicStandUpRcRightBankedOrthogonalToDiag2_2 = SPR_CSG_BEGIN + 67371;
static constexpr ImageIndex kClassicStandUpRcRightBankedOrthogonalToDiag2_3 = SPR_CSG_BEGIN + 67372;
static constexpr ImageIndex kClassicStandUpRcRightBankedOrthogonalToDiag3_0 = SPR_CSG_BEGIN + 67373;
static constexpr ImageIndex kClassicStandUpRcRightBankedOrthogonalToDiag3_1 = SPR_CSG_BEGIN + 67374;
static constexpr ImageIndex kClassicStandUpRcRightBankedOrthogonalToDiag3_2 = SPR_CSG_BEGIN + 67375;
static constexpr ImageIndex kClassicStandUpRcRightBankedOrthogonalToDiag3_3 = SPR_CSG_BEGIN + 67376;

static constexpr ImageIndex kClassicStandUpRcLeftBankedOrthogonalToDiag0_0 = SPR_CSG_BEGIN + 67377;
static constexpr ImageIndex kClassicStandUpRcLeftBankedOrthogonalToDiag0_1 = SPR_CSG_BEGIN + 67378;
static constexpr ImageIndex kClassicStandUpRcLeftBankedOrthogonalToDiag0_2 = SPR_CSG_BEGIN + 67379;
static constexpr ImageIndex kClassicStandUpRcLeftBankedOrthogonalToDiag0_3 = SPR_CSG_BEGIN + 67380;
static constexpr ImageIndex kClassicStandUpRcLeftBankedOrthogonalToDiag1_0 = SPR_CSG_BEGIN + 67381;
static constexpr ImageIndex kClassicStandUpRcLeftBankedOrthogonalToDiag1_1 = SPR_CSG_BEGIN + 67382;
static constexpr ImageIndex kClassicStandUpRcLeftBankedOrthogonalToDiag1_2 = SPR_CSG_BEGIN + 67383;
static constexpr ImageIndex kClassicStandUpRcLeftBankedOrthogonalToDiag1_3 = SPR_CSG_BEGIN + 67384;
static constexpr ImageIndex kClassicStandUpRcLeftBankedOrthogonalToDiag2_0 = SPR_CSG_BEGIN + 67385;
static constexpr ImageIndex kClassicStandUpRcLeftBankedOrthogonalToDiag2_1 = SPR_CSG_BEGIN + 67386;
static constexpr ImageIndex kClassicStandUpRcLeftBankedOrthogonalToDiag2_2 = SPR_CSG_BEGIN + 67387;
static constexpr ImageIndex kClassicStandUpRcLeftBankedOrthogonalToDiag2_3 = SPR_CSG_BEGIN + 67388;
static constexpr ImageIndex kClassicStandUpRcLeftBankedOrthogonalToDiag3_0 = SPR_CSG_BEGIN + 67389;
static constexpr ImageIndex kClassicStandUpRcLeftBankedOrthogonalToDiag3_1 = SPR_CSG_BEGIN + 67390;
static constexpr ImageIndex kClassicStandUpRcLeftBankedOrthogonalToDiag3_2 = SPR_CSG_BEGIN + 67391;
static constexpr ImageIndex kClassicStandUpRcLeftBankedOrthogonalToDiag3_3 = SPR_CSG_BEGIN + 67392;

static constexpr ImageIndex kClassicStandUpRcRightBankedStraightDiag0 = SPR_CSG_BEGIN + 67421; 
static constexpr ImageIndex kClassicStandUpRcRightBankedStraightDiag1 = SPR_CSG_BEGIN + 67422; 
static constexpr ImageIndex kClassicStandUpRcRightBankedStraightDiag2 = SPR_CSG_BEGIN + 67423; 
static constexpr ImageIndex kClassicStandUpRcRightBankedStraightDiag3 = SPR_CSG_BEGIN + 67424; 
static constexpr ImageIndex kClassicStandUpRcRightBankedToFlatStraightDiag0 = SPR_CSG_BEGIN + 67425; 
static constexpr ImageIndex kClassicStandUpRcRightBankedToFlatStraightDiag1 = SPR_CSG_BEGIN + 67426; 
static constexpr ImageIndex kClassicStandUpRcRightBankedToFlatStraightDiag2 = SPR_CSG_BEGIN + 67427; 
static constexpr ImageIndex kClassicStandUpRcRightBankedToFlatStraightDiag3 = SPR_CSG_BEGIN + 67428; 
static constexpr ImageIndex kClassicStandUpRcRightBankedStraightToDownDiag0 = SPR_CSG_BEGIN + 67433;
static constexpr ImageIndex kClassicStandUpRcRightBankedStraightToDownDiag1 = SPR_CSG_BEGIN + 67434;
static constexpr ImageIndex kClassicStandUpRcRightBankedStraightToDownDiag2 = SPR_CSG_BEGIN + 67435;
static constexpr ImageIndex kClassicStandUpRcRightBankedStraightToDownDiag3 = SPR_CSG_BEGIN + 67436;
static constexpr ImageIndex kClassicStandUpRcLeftBankedStraightToDownDiag0 = SPR_CSG_BEGIN + 67437;
static constexpr ImageIndex kClassicStandUpRcLeftBankedStraightToDownDiag1 = SPR_CSG_BEGIN + 67438;
static constexpr ImageIndex kClassicStandUpRcLeftBankedStraightToDownDiag2 = SPR_CSG_BEGIN + 67439;
static constexpr ImageIndex kClassicStandUpRcLeftBankedStraightToDownDiag3 = SPR_CSG_BEGIN + 67440;
static constexpr ImageIndex kClassicStandUpRcDownStraightToRightBankedFlatDiag0 = SPR_CSG_BEGIN + 67441;
static constexpr ImageIndex kClassicStandUpRcDownStraightToRightBankedFlatDiag1 = SPR_CSG_BEGIN + 67442;
static constexpr ImageIndex kClassicStandUpRcDownStraightToRightBankedFlatDiag2 = SPR_CSG_BEGIN + 67443;
static constexpr ImageIndex kClassicStandUpRcDownStraightToRightBankedFlatDiag3 = SPR_CSG_BEGIN + 67444;
static constexpr ImageIndex kClassicStandUpRcDownStraightToLeftBankedFlatDiag0 = SPR_CSG_BEGIN + 67445;
static constexpr ImageIndex kClassicStandUpRcDownStraightToLeftBankedFlatDiag1 = SPR_CSG_BEGIN + 67446;
static constexpr ImageIndex kClassicStandUpRcDownStraightToLeftBankedFlatDiag2 = SPR_CSG_BEGIN + 67447;
static constexpr ImageIndex kClassicStandUpRcDownStraightToLeftBankedFlatDiag3 = SPR_CSG_BEGIN + 67448;



#pragma GCC diagnostic pop

static void classicStandUpRCTrackFlatToLeftBank(
    PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TrackElement& trackElement)
{
    static constexpr ImageIndex map[NumOrthogonalDirections] = {
        kClassicStandUpRcFlatToLeftBank0,
        kClassicStandUpRcFlatToLeftBank1,
        kClassicStandUpRcFlatToLeftBank2,
        kClassicStandUpRcFlatToLeftBank3,
    };
    
    PaintAddImageAsParentRotated(
        session, direction, session.TrackColours.WithIndex(map[direction]), { 0, 6, height }, { 32, 20, 3 });
    
    if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
    {
        MetalASupportsPaintSetup(
            session, MetalSupportType::Tubes, MetalSupportPlace::Centre, 0, height, session.SupportColours);
    }
    
    PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_0);
    PaintUtilSetSegmentSupportHeight(
        session,
        PaintUtilRotateSegments(
            EnumsToFlags(PaintSegment::centre, PaintSegment::topRightSide, PaintSegment::bottomLeftSide), direction),
        0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
}

static void classicStandUpRCTrackFlatToRightBank(
    PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TrackElement& trackElement)
{
    static constexpr ImageIndex map[NumOrthogonalDirections] = {
        kClassicStandUpRcFlatToRightBank0,
        kClassicStandUpRcFlatToRightBank1,
        kClassicStandUpRcFlatToRightBank2,
        kClassicStandUpRcFlatToRightBank3,
    };
    
    PaintAddImageAsParentRotated(
        session, direction, session.TrackColours.WithIndex(map[direction]), { 0, 6, height }, { 32, 20, 3 });
    
    if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
    {
        MetalASupportsPaintSetup(
            session, MetalSupportType::Tubes, MetalSupportPlace::Centre, 0, height, session.SupportColours);
    }
    
    PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_0);
    PaintUtilSetSegmentSupportHeight(
        session,
        PaintUtilRotateSegments(
            EnumsToFlags(PaintSegment::centre, PaintSegment::topRightSide, PaintSegment::bottomLeftSide), direction),
        0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
}

static void classicStandUpRCTrackLeftBankToFlat(
    PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TrackElement& trackElement)
{
    return classicStandUpRCTrackFlatToRightBank(session, ride, trackSequence, (direction + 2) % NumOrthogonalDirections, height, trackElement);
}

static void classicStandUpRCTrackRightBankToFlat(
    PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TrackElement& trackElement)
{
    return classicStandUpRCTrackFlatToLeftBank(session, ride, trackSequence, (direction + 2) % NumOrthogonalDirections, height, trackElement);
}

static void classicStandUpRCTrackBankedRightQuarterTurn5(
    PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TrackElement& trackElement)
{
    switch (trackSequence)
    {
        case 0:
        {
            constexpr ImageIndex map[NumOrthogonalDirections] = {
                kClassicStandUpRcRightTurn5TilesBanked0_0,
                kClassicStandUpRcRightTurn5TilesBanked1_0,
                kClassicStandUpRcRightTurn5TilesBanked2_0,
                kClassicStandUpRcRightTurn5TilesBanked3_0,
            };

            PaintAddImageAsParentRotated(session, direction, session.TrackColours.WithIndex(map[direction]), { 0, 6, height }, { 32, 20, 3 });

            MetalASupportsPaintSetup(
                session, MetalSupportType::Tubes, MetalSupportPlace::Centre, 0, height, session.SupportColours);
            switch (direction)
            {
                case 0:
                    PaintUtilPushTunnelLeft(session, height, TUNNEL_0);
                    break;
                case 3:
                    PaintUtilPushTunnelRight(session, height, TUNNEL_0);
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session,
                PaintUtilRotateSegments(
                    EnumsToFlags(
                        PaintSegment::rightCorner, PaintSegment::centre, PaintSegment::bottomLeftSide,
                        PaintSegment::topRightSide),
                    direction),
                0xFFFF, 0);
            break;
        }
        case 1:
            break;
            
        case 2:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(kClassicStandUpRcRightTurn5TilesBanked0_1), { 0, 16, height }, { 32, 16, 3 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(kClassicStandUpRcRightTurn5TilesBanked1_1), { 0, 16, height }, { 32, 16, 3 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(kClassicStandUpRcRightTurn5TilesBanked2_1), { 0, 0, height }, { 32, 16, 3 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(kClassicStandUpRcRightTurn5TilesBanked3_1), { 0, 0, height }, { 32, 16, 3 });
                    break;
                
            }
            PaintUtilSetSegmentSupportHeight(
                session,
                PaintUtilRotateSegments(
                    EnumsToFlags(
                        PaintSegment::bottomCorner, PaintSegment::rightCorner, PaintSegment::centre,
                        PaintSegment::bottomLeftSide, PaintSegment::bottomRightSide, PaintSegment::topRightSide),
                    direction),
                0xFFFF, 0);
            break;
            
        case 3:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(kClassicStandUpRcRightTurn5TilesBanked0_2), { 0, 0, height }, { 16, 16, 3 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(kClassicStandUpRcRightTurn5TilesBanked1_2), { 16, 0, height }, { 16, 16, 3 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(kClassicStandUpRcRightTurn5TilesBanked2_2), { 16, 16, height }, { 16, 16, 3 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(kClassicStandUpRcRightTurn5TilesBanked3_2), { 0, 16, height }, { 16, 16, 3 });
                    break;

            }
            PaintUtilSetSegmentSupportHeight(
                session,
                PaintUtilRotateSegments(
                    EnumsToFlags(
                        PaintSegment::topCorner, PaintSegment::centre, PaintSegment::topLeftSide, PaintSegment::topRightSide),
                    direction),
                0xFFFF, 0);
            break;
            
        case 4:
            break;
            
        case 5:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(kClassicStandUpRcRightTurn5TilesBanked0_3), { 16, 0, height }, { 16, 32, 3 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(kClassicStandUpRcRightTurn5TilesBanked1_3), { 0, 0, height }, { 16, 32, 3 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(kClassicStandUpRcRightTurn5TilesBanked2_3), { 0, 0, height }, { 16, 32, 3 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(kClassicStandUpRcRightTurn5TilesBanked3_3), { 16, 0, height }, { 16, 32, 3 });
                    break;
                
            }
            PaintUtilSetSegmentSupportHeight(
                session,
                PaintUtilRotateSegments(
                    EnumsToFlags(
                        PaintSegment::leftCorner, PaintSegment::bottomCorner, PaintSegment::centre,
                        PaintSegment::bottomLeftSide, PaintSegment::topLeftSide, PaintSegment::bottomRightSide),
                    direction),
                0xFFFF, 0);
            break;

        case 6:
        {
            constexpr ImageIndex map[NumOrthogonalDirections] = {
                kClassicStandUpRcRightTurn5TilesBanked0_4,
                kClassicStandUpRcRightTurn5TilesBanked1_4,
                kClassicStandUpRcRightTurn5TilesBanked2_4,
                kClassicStandUpRcRightTurn5TilesBanked3_4,
            };
            
            PaintAddImageAsParentRotated(
                session, direction, session.TrackColours.WithIndex(map[direction]), { 6, 0, height }, { 20, 32, 3 });
            
            MetalASupportsPaintSetup(
                session, MetalSupportType::Tubes, MetalSupportPlace::Centre, 0, height, session.SupportColours);
            if (direction == 1 || direction == 0)
            {
                PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_0);
            }
            PaintUtilSetSegmentSupportHeight(
                session,
                PaintUtilRotateSegments(
                    EnumsToFlags(
                        PaintSegment::leftCorner, PaintSegment::centre, PaintSegment::topLeftSide,
                        PaintSegment::bottomRightSide),
                    direction),
                0xFFFF, 0);
            break;
        }
    }
    
    PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
}

static void classicStandUpRCTrackBankedLeftQuarterTurn5(
    PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TrackElement& trackElement)
{
    trackSequence = mapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence];
    direction = (direction + 1) % NumOrthogonalDirections;
    return classicStandUpRCTrackBankedRightQuarterTurn5(session, ride, trackSequence, direction, height, trackElement);
}

static void classicStandUpRCTrackLeftBankTo25DegUp(
    PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TrackElement& trackElement)
{
    static constexpr ImageIndex map[NumOrthogonalDirections] = {
        kClassicStandUpRcLeftBankedTo25DegUp0,
        kClassicStandUpRcLeftBankedTo25DegUp1,
        kClassicStandUpRcLeftBankedTo25DegUp2,
        kClassicStandUpRcLeftBankedTo25DegUp3,
    };
    
    
    PaintAddImageAsParentRotated(
        session, direction, session.TrackColours.WithIndex(map[direction]), { 0, 6, height }, { 32, 20, 3 });

    if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
    {
        MetalASupportsPaintSetup(
            session, MetalSupportType::Tubes, MetalSupportPlace::Centre, 3, height, session.SupportColours);
    }
    
    if (direction == 0 || direction == 3)
    {
        PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_0);
    }
    else
    {
        PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_2);
    }
    PaintUtilSetSegmentSupportHeight(
        session,
        PaintUtilRotateSegments(
            EnumsToFlags(PaintSegment::centre, PaintSegment::topRightSide, PaintSegment::bottomLeftSide), direction),
        0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
}

static void classicStandUpRCTrackRightBankTo25DegUp(
    PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TrackElement& trackElement)
{
    static constexpr ImageIndex map[NumOrthogonalDirections] = {
        kClassicStandUpRcRightBankedTo25DegUp0,
        kClassicStandUpRcRightBankedTo25DegUp1,
        kClassicStandUpRcRightBankedTo25DegUp2,
        kClassicStandUpRcRightBankedTo25DegUp3,
    };
    
    PaintAddImageAsParentRotated(
        session, direction, session.TrackColours.WithIndex(map[direction]), { 0, 6, height }, { 32, 20, 3 });
    
    if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
    {
        MetalASupportsPaintSetup(
            session, MetalSupportType::Tubes, MetalSupportPlace::Centre, 3, height, session.SupportColours);
    }
    
    if (direction == 0 || direction == 3)
    {
        PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_0);
    }
    else
    {
        PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_2);
    }
    PaintUtilSetSegmentSupportHeight(
        session,
        PaintUtilRotateSegments(
            EnumsToFlags(PaintSegment::centre, PaintSegment::topRightSide, PaintSegment::bottomLeftSide), direction),
        0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
}

static void classicStandUpRCTrack25DegUpToLeftBank(
    PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TrackElement& trackElement)
{
    static constexpr ImageIndex map[NumOrthogonalDirections] = {
        kClassicStandUpRc25DegUpToFlatLeftBanked0,
        kClassicStandUpRc25DegUpToFlatLeftBanked1,
        kClassicStandUpRc25DegUpToFlatLeftBanked2,
        kClassicStandUpRc25DegUpToFlatLeftBanked3,
    };
    
    PaintAddImageAsParentRotated(
        session, direction, session.TrackColours.WithIndex(map[direction]), { 0, 6, height }, { 32, 20, 3 });

    if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
    {
        MetalASupportsPaintSetup(
            session, MetalSupportType::Tubes, MetalSupportPlace::Centre, 6, height, session.SupportColours);
    }
    
    if (direction == 0 || direction == 3)
    {
        PaintUtilPushTunnelRotated(session, direction, height - 8, TUNNEL_0);
    }
    else
    {
        PaintUtilPushTunnelRotated(session, direction, height + 8, TUNNEL_12);
    }
    PaintUtilSetSegmentSupportHeight(
        session,
        PaintUtilRotateSegments(
            EnumsToFlags(PaintSegment::centre, PaintSegment::topRightSide, PaintSegment::bottomLeftSide), direction),
        0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 40, 0x20);
}

static void classicStandUpRCTrack25DegUpToRightBank(
    PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TrackElement& trackElement)
{
    static constexpr ImageIndex map[NumOrthogonalDirections] = {
        kClassicStandUpRc25DegUpToFlatRightBanked0,
        kClassicStandUpRc25DegUpToFlatRightBanked1,
        kClassicStandUpRc25DegUpToFlatRightBanked2,
        kClassicStandUpRc25DegUpToFlatRightBanked3,
    };
    
    PaintAddImageAsParentRotated(
        session, direction, session.TrackColours.WithIndex(map[direction]), { 0, 6, height }, { 32, 20, 3 });
    
    if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
    {
        MetalASupportsPaintSetup(
            session, MetalSupportType::Tubes, MetalSupportPlace::Centre, 6, height, session.SupportColours);
    }
    
    if (direction == 0 || direction == 3)
    {
        PaintUtilPushTunnelRotated(session, direction, height - 8, TUNNEL_0);
    }
    else
    {
        PaintUtilPushTunnelRotated(session, direction, height + 8, TUNNEL_12);
    }
    PaintUtilSetSegmentSupportHeight(
        session,
        PaintUtilRotateSegments(
            EnumsToFlags(PaintSegment::centre, PaintSegment::topRightSide, PaintSegment::bottomLeftSide), direction),
        0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 40, 0x20);
}

static void classicStandUpRCTrackLeftBankTo25DegDown(
    PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TrackElement& trackElement)
{
    classicStandUpRCTrack25DegUpToRightBank(session, ride, trackSequence, (direction + 2) % NumOrthogonalDirections, height, trackElement);
}

static void classicStandUpRCTrackRightBankTo25DegDown(
    PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TrackElement& trackElement)
{
    classicStandUpRCTrack25DegUpToLeftBank(session, ride, trackSequence, (direction + 2) % NumOrthogonalDirections, height, trackElement);
}

static void classicStandUpRCTrack25DegDownToLeftBank(
    PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TrackElement& trackElement)
{
    classicStandUpRCTrackRightBankTo25DegUp(session, ride, trackSequence, (direction + 2) % NumOrthogonalDirections, height, trackElement);
}

static void classicStandUpRCTrack25DegDownToRightBank(
    PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TrackElement& trackElement)
{
    classicStandUpRCTrackLeftBankTo25DegUp(session, ride, trackSequence, (direction + 2) % NumOrthogonalDirections, height, trackElement);
}

static void classicStandUpRCTrackLeftBank(
    PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TrackElement& trackElement)
{
    static constexpr ImageIndex map[NumOrthogonalDirections] = {
        kClassicStandUpRcLeftBanked0,
        kClassicStandUpRcLeftBanked1,
        kClassicStandUpRcLeftBanked2,
        kClassicStandUpRcLeftBanked3,
    } ;
    
    PaintAddImageAsParentRotated(
        session, direction, session.TrackColours.WithIndex(map[direction]), { 0, 6, height }, { 32, 20, 3 });
    
    if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
    {
        MetalASupportsPaintSetup(
            session, MetalSupportType::Tubes, MetalSupportPlace::Centre, 0, height, session.SupportColours);
    }
        
    PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_0);
    PaintUtilSetSegmentSupportHeight(
        session,
        PaintUtilRotateSegments(
            EnumsToFlags(PaintSegment::centre, PaintSegment::topRightSide, PaintSegment::bottomLeftSide), direction),
        0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
}

static void classicStandUpRCTrackRightBank(
    PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TrackElement& trackElement)
{
    return classicStandUpRCTrackLeftBank(session, ride, trackSequence, (direction + 2) % NumOrthogonalDirections, height, trackElement);
}

static void classicStandUpRCTrackLeftEighthBankToDiag(
    PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TrackElement& trackElement)
{
    static constexpr ImageIndex map[5][NumOrthogonalDirections] = {
        { kClassicStandUpRcLeftBankedOrthogonalToDiag0_0, kClassicStandUpRcLeftBankedOrthogonalToDiag1_0, kClassicStandUpRcLeftBankedOrthogonalToDiag2_0, kClassicStandUpRcLeftBankedOrthogonalToDiag3_0 },  
        { kClassicStandUpRcLeftBankedOrthogonalToDiag0_1, kClassicStandUpRcLeftBankedOrthogonalToDiag1_1, kClassicStandUpRcLeftBankedOrthogonalToDiag2_1, kClassicStandUpRcLeftBankedOrthogonalToDiag3_1 },  
        { kClassicStandUpRcLeftBankedOrthogonalToDiag0_2, kClassicStandUpRcLeftBankedOrthogonalToDiag1_2, kClassicStandUpRcLeftBankedOrthogonalToDiag2_2, kClassicStandUpRcLeftBankedOrthogonalToDiag3_2 },  
        { ImageIndexUndefined, ImageIndexUndefined, ImageIndexUndefined, ImageIndexUndefined },  
        { kClassicStandUpRcLeftBankedOrthogonalToDiag0_3, kClassicStandUpRcLeftBankedOrthogonalToDiag1_3, kClassicStandUpRcLeftBankedOrthogonalToDiag2_3, kClassicStandUpRcLeftBankedOrthogonalToDiag3_3 },
    };
    
    const auto imageId = map[trackSequence][direction];
    
    switch (trackSequence)
    {
        case 0:
            PaintAddImageAsParentRotated(
                session, direction, session.TrackColours.WithIndex(imageId), { 0, 0, height },
                { { 0, 6, height }, { 32, 20, 3 } });
            
            MetalASupportsPaintSetup(
                session, MetalSupportType::Tubes, MetalSupportPlace::Centre, 0, height, session.SupportColours);
            if (direction == 0 || direction == 3)
            {
                PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_0);
            }
            PaintUtilSetSegmentSupportHeight(
                session,
                PaintUtilRotateSegments(
                    EnumsToFlags(PaintSegment::centre, PaintSegment::topRightSide, PaintSegment::bottomLeftSide), direction),
                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 1:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(imageId), { 0, 0, height },
                        { { 0, 0, height }, { 32, 16, 3 } });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(imageId), { 0, 0, height },
                        { { 0, 0, height }, { 34, 16, 3 } });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(imageId), { 0, 0, height },
                        { { 0, 16, height }, { 32, 16, 3 } });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(imageId), { 0, 0, height },
                        { { 0, 16, height }, { 32, 16, 3 } });
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session,
                PaintUtilRotateSegments(
                    EnumsToFlags(
                        PaintSegment::topCorner, PaintSegment::leftCorner, PaintSegment::centre, PaintSegment::topLeftSide,
                        PaintSegment::topRightSide, PaintSegment::bottomLeftSide),
                    direction),
                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 2:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(imageId), { 0, 0, height },
                        { { 0, 16, height }, { 16, 16, 3 } });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(imageId), { 0, 0, height },
                        { { 16, 16, height }, { 16, 16, 3 } });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(imageId), { 0, 0, height },
                        { { 16, 0, height }, { 16, 16, 3 } });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(imageId), { 0, 0, height },
                        { { 0, 0, height }, { 16, 16, 3 } });
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session,
                PaintUtilRotateSegments(
                    EnumsToFlags(
                        PaintSegment::rightCorner, PaintSegment::bottomCorner, PaintSegment::centre, PaintSegment::topRightSide,
                        PaintSegment::bottomRightSide),
                    direction),
                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 3:
            PaintUtilSetSegmentSupportHeight(
                session,
                PaintUtilRotateSegments(
                    EnumsToFlags(
                        PaintSegment::leftCorner, PaintSegment::centre, PaintSegment::topLeftSide,
                        PaintSegment::bottomLeftSide),
                    direction),
                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 4:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(imageId), { 0, 0, height },
                        { { 16, 16, height }, { 16, 16, 3 } });
                    MetalASupportsPaintSetup(
                        session, MetalSupportType::Tubes, MetalSupportPlace::BottomCorner, 0, height, session.SupportColours);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(imageId), { 0, 0, height },
                        { { 0, 16, height }, { 16, 18, 3 } });
                    MetalASupportsPaintSetup(
                        session, MetalSupportType::Tubes, MetalSupportPlace::LeftCorner, 0, height, session.SupportColours);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(imageId), { 0, 0, height },
                        { { 0, 0, height }, { 16, 16, 3 } });
                    MetalASupportsPaintSetup(
                        session, MetalSupportType::Tubes, MetalSupportPlace::TopCorner, 0, height, session.SupportColours);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(imageId), { 0, 0, height },
                        { { 16, 0, height }, { 16, 16, 3 } });
                    MetalASupportsPaintSetup(
                        session, MetalSupportType::Tubes, MetalSupportPlace::RightCorner, 0, height, session.SupportColours);
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session,
                PaintUtilRotateSegments(
                    EnumsToFlags(
                        PaintSegment::bottomCorner, PaintSegment::centre, PaintSegment::topLeftSide, PaintSegment::topRightSide,
                        PaintSegment::bottomLeftSide, PaintSegment::bottomRightSide),
                    direction),
                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
    }
}

static void classicStandUpRCTrackRightEighthBankToDiag(
    PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TrackElement& trackElement)
{
    static constexpr ImageIndex map[5][NumOrthogonalDirections] = {
        { kClassicStandUpRcRightBankedOrthogonalToDiag0_0, kClassicStandUpRcRightBankedOrthogonalToDiag1_0, kClassicStandUpRcRightBankedOrthogonalToDiag2_0, kClassicStandUpRcRightBankedOrthogonalToDiag3_0 },  
        { kClassicStandUpRcRightBankedOrthogonalToDiag0_1, kClassicStandUpRcRightBankedOrthogonalToDiag1_1, kClassicStandUpRcRightBankedOrthogonalToDiag2_1, kClassicStandUpRcRightBankedOrthogonalToDiag3_1 },  
        { kClassicStandUpRcRightBankedOrthogonalToDiag0_2, kClassicStandUpRcRightBankedOrthogonalToDiag1_2, kClassicStandUpRcRightBankedOrthogonalToDiag2_2, kClassicStandUpRcRightBankedOrthogonalToDiag3_2 },  
        { ImageIndexUndefined, ImageIndexUndefined, ImageIndexUndefined, ImageIndexUndefined },  
        { kClassicStandUpRcRightBankedOrthogonalToDiag0_3, kClassicStandUpRcRightBankedOrthogonalToDiag1_3, kClassicStandUpRcRightBankedOrthogonalToDiag2_3, kClassicStandUpRcRightBankedOrthogonalToDiag3_3 },
    };
    
    const auto imageId = map[trackSequence][direction];
    
    switch (trackSequence)
    {
        case 0:
            PaintAddImageAsParentRotated(
                session, direction, session.TrackColours.WithIndex(imageId), { 0, 0, height }, { { 0, 6, height }, { 32, 20, 3 } });
            
            MetalASupportsPaintSetup(
                session, MetalSupportType::Tubes, MetalSupportPlace::Centre, 0, height, session.SupportColours);
            if (direction == 0 || direction == 3)
            {
                PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_0);
            }
            PaintUtilSetSegmentSupportHeight(
                session,
                PaintUtilRotateSegments(
                    EnumsToFlags(PaintSegment::centre, PaintSegment::topRightSide, PaintSegment::bottomLeftSide), direction),
                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 1:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(imageId), { 0, 0, height },
                        { { 0, 16, height }, { 32, 16, 3 } });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(imageId), { 0, 0, height },
                        { { 0, 16, height }, { 32, 16, 3 } });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(imageId), { 0, 0, height },
                        { { 0, 0, height }, { 34, 16, 3 } });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(imageId), { 0, 0, height },
                        { { 0, 0, height }, { 32, 16, 3 } });
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session,
                PaintUtilRotateSegments(
                    EnumsToFlags(
                        PaintSegment::rightCorner, PaintSegment::bottomCorner, PaintSegment::centre, PaintSegment::topRightSide,
                        PaintSegment::bottomLeftSide, PaintSegment::bottomRightSide),
                    direction),
                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 2:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(imageId), { 0, 0, height },
                        { { 0, 0, height }, { 16, 16, 3 } });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(imageId), { 0, 0, height },
                        { { 16, 0, height }, { 16, 16, 3 } });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(imageId), { 0, 0, height },
                        { { 4, 4, height }, { 28, 28, 3 } });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(imageId), { 0, 0, height },
                        { { 0, 16, height }, { 16, 16, 3 } });
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session,
                PaintUtilRotateSegments(
                    EnumsToFlags(
                        PaintSegment::topCorner, PaintSegment::leftCorner, PaintSegment::centre, PaintSegment::topLeftSide,
                        PaintSegment::topRightSide),
                    direction),
                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 3:
            PaintUtilSetSegmentSupportHeight(
                session,
                PaintUtilRotateSegments(
                    EnumsToFlags(
                        PaintSegment::bottomCorner, PaintSegment::centre, PaintSegment::bottomLeftSide,
                        PaintSegment::bottomRightSide),
                    direction),
                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 4:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(imageId), { 0, 0, height },
                        { { 16, 0, height }, { 16, 16, 3 } });
                    MetalASupportsPaintSetup(
                        session, MetalSupportType::Tubes, MetalSupportPlace::LeftCorner, 0, height, session.SupportColours);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(imageId), { 0, 0, height },
                        { { 0, 0, height }, { 16, 16, 3 } });
                    MetalASupportsPaintSetup(
                        session, MetalSupportType::Tubes, MetalSupportPlace::TopCorner, 0, height, session.SupportColours);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(imageId), { 0, 0, height },
                        { { 0, 16, height }, { 16, 18, 3 } });
                    MetalASupportsPaintSetup(
                        session, MetalSupportType::Tubes, MetalSupportPlace::RightCorner, 0, height, session.SupportColours);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(imageId), { 0, 0, height },
                        { { 16, 16, height }, { 16, 16, 3 } });
                    MetalASupportsPaintSetup(
                        session, MetalSupportType::Tubes, MetalSupportPlace::BottomCorner, 0, height, session.SupportColours);
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session,
                PaintUtilRotateSegments(
                    EnumsToFlags(
                        PaintSegment::leftCorner, PaintSegment::centre, PaintSegment::topLeftSide, PaintSegment::topRightSide,
                        PaintSegment::bottomLeftSide, PaintSegment::bottomRightSide),
                    direction),
                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
    }
}

static void classicStandUpRCTrackLeftEighthDiagBankToOrthogonal(
    PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TrackElement& trackElement)
{
    trackSequence = mapLeftEighthTurnToOrthogonal[trackSequence];
    direction = (direction + 2) % NumOrthogonalDirections;
    classicStandUpRCTrackRightEighthBankToDiag(session, ride, trackSequence, direction, height, trackElement);
}

static void classicStandUpRCTrackRightEighthDiagBankToOrthogonal(
    PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TrackElement& trackElement)
{
    trackSequence = mapLeftEighthTurnToOrthogonal[trackSequence];
    direction = (direction + 3) % NumOrthogonalDirections;
    classicStandUpRCTrackLeftEighthBankToDiag(session, ride, trackSequence, direction, height, trackElement);
}

TRACK_PAINT_FUNCTION GetTrackPaintFunctionClassicStandUpRC(int32_t trackType)
{
    switch (trackType)
    {
        case TrackElemType::FlatToLeftBank:
            return classicStandUpRCTrackFlatToLeftBank;
        case TrackElemType::FlatToRightBank:
            return classicStandUpRCTrackFlatToRightBank;
        case TrackElemType::LeftBankToFlat:
            return classicStandUpRCTrackLeftBankToFlat;
        case TrackElemType::RightBankToFlat:
            return classicStandUpRCTrackRightBankToFlat;
        case TrackElemType::BankedLeftQuarterTurn5Tiles:
            return classicStandUpRCTrackBankedLeftQuarterTurn5;
        case TrackElemType::BankedRightQuarterTurn5Tiles:
            return classicStandUpRCTrackBankedRightQuarterTurn5;
        case TrackElemType::LeftBankToUp25:
            return classicStandUpRCTrackLeftBankTo25DegUp;
        case TrackElemType::RightBankToUp25:
            return classicStandUpRCTrackRightBankTo25DegUp;
        case TrackElemType::Up25ToLeftBank:
            return classicStandUpRCTrack25DegUpToLeftBank;
        case TrackElemType::Up25ToRightBank:
            return classicStandUpRCTrack25DegUpToRightBank;
        case TrackElemType::LeftBankToDown25:
            return classicStandUpRCTrackLeftBankTo25DegDown;
        case TrackElemType::RightBankToDown25:
            return classicStandUpRCTrackRightBankTo25DegDown;
        case TrackElemType::Down25ToLeftBank:
            return classicStandUpRCTrack25DegDownToLeftBank;
        case TrackElemType::Down25ToRightBank:
            return classicStandUpRCTrack25DegDownToRightBank;
        case TrackElemType::LeftBank:
            return classicStandUpRCTrackLeftBank;
        case TrackElemType::RightBank:
            return classicStandUpRCTrackRightBank;

        case TrackElemType::LeftEighthBankToDiag:
            return classicStandUpRCTrackLeftEighthBankToDiag;
        case TrackElemType::RightEighthBankToDiag:
            return classicStandUpRCTrackRightEighthBankToDiag;
        case TrackElemType::LeftEighthBankToOrthogonal:
            return classicStandUpRCTrackLeftEighthDiagBankToOrthogonal;
        case TrackElemType::RightEighthBankToOrthogonal:
            return classicStandUpRCTrackRightEighthDiagBankToOrthogonal;

        case TrackElemType::LeftBankedQuarterTurn3Tiles:
        case TrackElemType::RightBankedQuarterTurn3Tiles:
        case TrackElemType::DiagFlatToLeftBank:
        case TrackElemType::DiagFlatToRightBank:
        case TrackElemType::DiagLeftBankToFlat:
        case TrackElemType::DiagRightBankToFlat:
        case TrackElemType::DiagLeftBankToUp25:
        case TrackElemType::DiagRightBankToUp25:
        case TrackElemType::DiagUp25ToLeftBank:
        case TrackElemType::DiagUp25ToRightBank:
        case TrackElemType::DiagLeftBankToDown25:
        case TrackElemType::DiagRightBankToDown25:
        case TrackElemType::DiagDown25ToLeftBank:
        case TrackElemType::DiagDown25ToRightBank:
        case TrackElemType::DiagLeftBank:
        case TrackElemType::DiagRightBank:
            return nullptr;
    }

    return GetTrackPaintFunctionStandUpRC(trackType);
}
