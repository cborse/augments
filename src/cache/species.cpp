//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#include "species.h"
#include "error.h"

Species::Species(const nlohmann::json& json)
{
    try {
        id = json.at("id");
        name = json.at("name");
        rarity = json.at("rarity");
        type1 = json.at("type1");
        type2 = json.at("type2");
        type3 = json.at("type3");
    }
    catch (...) {
        throw Error("Failed to parse species data.");
    }
}

int Species::get_needed_egg_wins() const
{
    return (int)pow(2, (int)rarity + 1);
}
