//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include "enums.h"
#include "nlohmann/json.hpp"

class Action {
public:
    Action() = default;
    explicit Action(const nlohmann::json& json);

    static std::string get_cover_string(CoverID cover);
    static std::string get_style_string(StyleID style);

    ActionID id = ACTION_NONE;
    std::string name;
    TypeID type = TYPE_NONE;
    bool core = false;
    EffectID effect = EFFECT_NONE;
    uint8_t effect_chance = 0;
    CoverID cover = COVER_NONE;
    StyleID style = STYLE_NONE;
    bool detect = 0;
    uint8_t power = 0;
    uint8_t speed = 0;
    uint8_t energy = 0;
    uint8_t accuracy = 0;
    bool contact = 0;
    CoverID move = COVER_NONE;
    std::string desc1;
    std::string desc2;
    std::string desc3;
};
