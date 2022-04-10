#pragma once

#include <cstdint>
#include <string>
#include "enums.h"

struct Action {
    ActionID id;
    std::string name;
    TypeID type;
    bool core;
    EffectID effect;
    uint8_t effect_chance;
    CoverID cover;
    StyleID style;
    bool detect;
    uint8_t power;
    uint8_t speed;
    uint8_t energy;
    uint8_t accuracy;
    bool contact;
    CoverID move;
    std::string desc1;
    std::string desc2;
    std::string desc3;
};
