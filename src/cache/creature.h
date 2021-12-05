//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include "nlohmann/json.hpp"

class Creature {
public:
    Creature() = default;
    explicit Creature(const nlohmann::json& json);

    int get_level() const;
    float get_level_progress() const;

    uint32_t id = 0;
    uint32_t user_id = 0;
    uint32_t species_id = 0;
    int8_t staff_slot = 0;
    std::string name;
    bool egg = false;
    uint32_t xp = 0;
    uint32_t wins = 0;

private:
    static int get_xp(int level);
};
