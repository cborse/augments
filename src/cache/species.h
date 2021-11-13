//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include "enums.h"
#include "nlohmann/json.hpp"

class Species {
public:
    Species() = default;
    explicit Species(const nlohmann::json& json);

    int get_needed_egg_wins() const;

    uint32_t id = 0;
    std::string name;
    Rarity rarity = Rarity::common;
    Type type1 = Type::none;
    Type type2 = Type::none;
    uint32_t height = 0;
    uint32_t weight = 0;
    uint8_t inner_power = 0;
    uint8_t inner_defense = 0;
    uint8_t outer_power = 0;
    uint8_t outer_defense = 0;
    uint8_t move_speed = 0;
    uint8_t action_speed = 0;
    uint8_t stamina = 0;
    uint8_t accuracy = 0;
    uint8_t evasion = 0;
};
