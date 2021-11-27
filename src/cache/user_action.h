//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include "nlohmann/json.hpp"

class UserAction {
public:
    UserAction() = default;
    explicit UserAction(const nlohmann::json& json);

    uint64_t user_id = 0;
    uint32_t action_id = 0;
    uint8_t qty = 0;
};
