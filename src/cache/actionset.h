//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include "enums.h"
#include "nlohmann/json.hpp"

class Actionset {
public:
    Actionset() = default;
    explicit Actionset(const nlohmann::json& json);

    SpeciesID species_id = SPECIES_NONE;
    ActionID action_id = ACTION_NONE;
};
