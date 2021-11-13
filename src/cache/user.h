//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include "nlohmann/json.hpp"

class User {
public:
    User() = default;
    explicit User(const nlohmann::json& json);

    uint32_t id = 0;
    uint64_t steam_id = 0;
    std::string token;
    uint8_t egg_cap = 0;
    uint8_t storage_pages = 0;
};
