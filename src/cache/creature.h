#pragma once

#include <cstdint>
#include <string>
#include "enums.h"

struct Creature {
    int get_level() const
    {
        // total xp = floor(713/20736*A3^3+2*A3^2-A3)
        for (int i = 2; i <= 144; i++) {
            if (xp < (uint32_t)get_xp_at_level(i))
                return i - 1;
        }

        return 144;
    }

    float get_level_progress() const
    {
        int level = get_level();
        int xp_current_level = get_xp_at_level(level);
        int xp_next_level = get_xp_at_level(level + 1);
        return (xp - xp_current_level) / ((float)xp_next_level - xp_current_level);
    }

    static int get_xp_at_level(int level)
    {
        return (int)(713 / 20736. * pow(level, 3) + 2 * pow(level, 2) - level);
    }

    uint64_t id;
    SpeciesID species_id;
    int8_t staff_slot;
    std::string name;
    bool egg;
    uint32_t xp;
    uint32_t wins;
    ActionID actions[3];
    SkillID skills[3];
};
