//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#include "staff.h"
#include "error.h"

Staff::Staff(const nlohmann::json& json)
{
    try {
        id = json.at("id");
        user_id = json.at("user_id");
        name = json.at("name");
    }
    catch (...) {
        throw Error("Failed to parse staff data.");
    }
}
