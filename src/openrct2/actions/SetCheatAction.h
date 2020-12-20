/*****************************************************************************
 * Copyright (c) 2014-2020 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include "GameAction.h"

DEFINE_GAME_ACTION(SetCheatAction, GAME_COMMAND_CHEAT, GameActions::Result)
{
    using ParametersRange = std::pair<std::pair<int32_t, int32_t>, std::pair<int32_t, int32_t>>;

private:
    NetworkCheatType_t _cheatType{ EnumValue(CheatType::Count) };
    int32_t _param1{};
    int32_t _param2{};

public:
    SetCheatAction() = default;
    SetCheatAction(CheatType cheatType, int32_t param1 = 0, int32_t param2 = 0);

    void AcceptParameters(GameActionParameterVisitor & visitor) override;

    uint16_t GetActionFlags() const override;

    void Serialise(DataSerialiser & stream) override;
    GameActions::Result::Ptr Query() const override;
    GameActions::Result::Ptr Execute() const override;

private:
    ParametersRange GetParameterRange(CheatType cheatType) const;
    void SetGrassLength(int32_t length) const;
    void WaterPlants() const;
    void FixVandalism() const;
    void RemoveLitter() const;
    void FixBrokenRides() const;
    void RenewRides() const;
    void MakeDestructible() const;
    void ResetRideCrashStatus() const;
    void Set10MinuteInspection() const;
    void SetScenarioNoMoney(bool enabled) const;
    void SetMoney(money32 amount) const;
    void AddMoney(money32 amount) const;
    void ClearLoan() const;
    void GenerateGuests(int32_t count) const;
    void SetGuestParameter(int32_t parameter, int32_t value) const;
    void GiveObjectToGuests(int32_t object) const;
    void RemoveAllGuests() const;
    void SetStaffSpeed(uint8_t value) const;
    void OwnAllLand() const;
    void ParkSetOpen(bool isOpen) const;
    void CreateDucks(int count) const;
};
