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

    static std::string get_cover_string(uint8_t cover);
    static std::string get_style_string(uint8_t style);

    uint32_t id = 0;
    std::string name;
    TypeID type = TYPE_NONE;
    bool core = false;
    uint8_t effect = 0;
    uint8_t effect_chance = 0;
    uint8_t cover = 0;
    uint8_t style = 0;
    bool detect = 0;
    uint8_t power = 0;
    uint8_t speed = 0;
    uint8_t energy = 0;
    uint8_t accuracy = 0;
    bool contact = 0;
    uint8_t move = 0;
    std::string desc1;
    std::string desc2;
    std::string desc3;
};
