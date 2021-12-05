//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include "nlohmann/json.hpp"

class Skillset {
public:
    Skillset() = default;
    explicit Skillset(const nlohmann::json& json);

    uint32_t species_id = 0;
    uint32_t skill_id = 0;
};
