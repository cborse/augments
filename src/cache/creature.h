#pragma once

#include <cstdint>
#include <string>
#include "enums.h"

struct Creature {
    int get_level() const
    {
        return wins / 12 + 1;
    }

    uint64_t id;
    SpeciesID species_id;
    int8_t staff_slot;
    std::string name;
    bool egg;
    uint32_t wins;
    ActionID actions[3];
    SkillID skills[3];
};
