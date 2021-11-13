//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#include "cache.h"

void Cache::init(const nlohmann::json& json)
{
    // Species
    species.clear();
    for (const auto& obj : json.at("species"))
        species.emplace_back(obj);

    // User
    user = User(json.at("user"));

    // Staffs
    staffs.clear();
    for (const auto& obj : json.at("staffs"))
        staffs.emplace_back(obj);

    // Creatures
    creatures.clear();
    for (const auto& obj : json.at("creatures"))
        creatures.emplace_back(obj);
}

const Species& Cache::get_species(uint32_t id) const
{
    return species.at(id);
}
