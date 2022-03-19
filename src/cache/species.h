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

    SpeciesID id = SPECIES_NONE;
    std::string name;
    RarityID rarity = RARITY_COMMON;
    TypeID type1 = TYPE_NONE;
    TypeID type2 = TYPE_NONE;
    TypeID type3 = TYPE_NONE;
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
