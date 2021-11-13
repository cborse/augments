//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#include "user.h"
#include "error.h"

User::User(const nlohmann::json& json)
{
    try {
        id = json.at("id");
        steam_id = json.at("steam_id");
        token = json.at("token");
        egg_cap = json.at("egg_cap");
        storage_pages = json.at("storage_pages");
    }
    catch (...) {
        throw Error("Failed to parse user data.");
    }
}
