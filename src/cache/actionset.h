//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include "nlohmann/json.hpp"

class Actionset {
public:
    Actionset() = default;
    explicit Actionset(const nlohmann::json& json);

    uint32_t species_id = 0;
    uint32_t action_id = 0;
};
