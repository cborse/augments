//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#include "skillset.h"
#include "error.h"

Skillset::Skillset(const nlohmann::json& json)
{
    try {
        species_id = json.at("species_id");
        skill_id = json.at("skill_id");
    }
    catch (...) {
        throw Error("Failed to parse skillset data.");
    }
}
