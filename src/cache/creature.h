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

    uint64_t id = 0;
    uint64_t user_id = 0;
    uint64_t staff_id = 0;
    uint32_t species_id = 0;
    std::string name;
    bool egg = false;
    uint32_t xp = 0;
    uint32_t wins = 0;
    uint32_t actions[3] = {};
    uint32_t skills[3] = {};

private:
    static int get_xp(int level);
};
