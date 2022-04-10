#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include "enums.h"

struct Species {
    SpeciesID id;
    std::string name;
    RarityID rarity;
    TypeID type1;
    TypeID type2;
    TypeID type3;
    uint32_t height;
    uint32_t weight;
    uint8_t inner_power;
    uint8_t inner_defense;
    uint8_t outer_power;
    uint8_t outer_defense;
    uint8_t move_speed;
    uint8_t act_speed;
    uint8_t stamina;
    uint8_t accuracy;
    uint8_t evasion;
    std::vector<ActionID> actionset;
    std::vector<SkillID> skillset;
};
