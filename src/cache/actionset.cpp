//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#include "actionset.h"
#include "error.h"

Actionset::Actionset(const nlohmann::json& json)
{
    try {
        species_id = json.at("species_id");
        action_id = json.at("action_id");
        series_id = json.at("series_id");
    }
    catch (...) {
        throw Error("Failed to parse actionset data.");
    }
}
