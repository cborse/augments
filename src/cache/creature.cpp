//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#include "creature.h"
#include "error.h"

Creature::Creature(const nlohmann::json& json)
{
    try {
        id = json.at("id");
        user_id = json.at("user_id");
        species_id = json.at("species_id");
        staff_slot = json.at("staff_slot");
        name = json.at("name");
        egg = json.at("egg");
        xp = json.at("xp");
        wins = json.at("wins");
        actions[0] = json.at("action1");
        actions[1] = json.at("action2");
        actions[2] = json.at("action3");
        skills[0] = json.at("skill1");
        skills[1] = json.at("skill2");
        skills[2] = json.at("skill3");
    }
    catch (...) {
        throw Error("Failed to parse creature data.");
    }
}

int Creature::get_level() const
{
    // total xp = floor(713/20736*A3^3+2*A3^2-A3)
    for (int i = 2; i <= 144; i++) {
        if (xp < (uint32_t)get_xp(i))
            return i - 1;
    }

    return 144;
}

float Creature::get_level_progress() const
{
    int level = get_level();
    int xp_current_level = get_xp(level);
    int xp_next_level = get_xp(level + 1);
    return (xp - xp_current_level) / ((float)xp_next_level - xp_current_level);
}

int Creature::get_xp(int level)
{
    return (int)(713 / 20736. * pow(level, 3) + 2 * pow(level, 2) - level);
}
