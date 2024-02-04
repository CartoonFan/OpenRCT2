/*****************************************************************************
 * Copyright (c) 2014-2024 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include "GameAction.h"

class PlayerSetGroupAction final : public GameActionBase<GameCommand::SetPlayerGroup>
{
private:
    NetworkPlayerId_t _playerId{ -1 };
    uint8_t _groupId{ std::numeric_limits<uint8_t>::max() };

public:
    PlayerSetGroupAction() = default;
    PlayerSetGroupAction(NetworkPlayerId_t playerId, uint8_t groupId);

    void AcceptParameters(GameActionParameterVisitor& visitor) override;

    uint16_t GetActionFlags() const override;

    void Serialise(DataSerialiser& stream) override;
    GameActions::Result Query() const override;
    GameActions::Result Execute() const override;
};
