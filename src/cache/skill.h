//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include "enums.h"
#include "nlohmann/json.hpp"

class Skill {
public:
    Skill() = default;
    explicit Skill(const nlohmann::json& json);

    uint32_t id = 0;
    std::string name;
    bool core = false;
    std::string desc1;
    std::string desc2;
    std::string desc3;
};
