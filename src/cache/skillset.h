//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include "enums.h"
#include "nlohmann/json.hpp"

class Skillset {
public:
    Skillset() = default;
    explicit Skillset(const nlohmann::json& json);

    SpeciesID species_id = SPECIES_NONE;
    SkillID skill_id = SKILL_NONE;
};
