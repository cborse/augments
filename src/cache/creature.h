//
// AUGMENTS
//
// Copyright 2022 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include "enums.h"
#include "nlohmann/json.hpp"

class Creature {
public:
    Creature() = default;
    explicit Creature(const nlohmann::json& json);

    int get_level() const;
    float get_level_progress() const;

    uint64_t id = 0;
    uint64_t user_id = 0;
    SpeciesID species_id = SPECIES_NONE;
    int8_t staff_slot = 0;
    std::string name;
    bool egg = false;
    uint32_t xp = 0;
    uint32_t wins = 0;
    ActionID actions[3] = {};
    SkillID skills[3] = {};

private:
    static int get_xp(int level);
};
