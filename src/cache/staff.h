//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include "nlohmann/json.hpp"

class Staff {
public:
    Staff() = default;
    explicit Staff(const nlohmann::json& json);

    uint64_t user_id = 0;
    uint8_t slot = 0;
    std::string name;
};
