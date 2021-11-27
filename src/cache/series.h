//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include "nlohmann/json.hpp"

class Series {
public:
    Series() = default;
    explicit Series(const nlohmann::json& json);

    uint8_t id = 0;
    std::string name;
};
