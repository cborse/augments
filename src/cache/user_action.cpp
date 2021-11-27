//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#include "user_action.h"
#include "error.h"

UserAction::UserAction(const nlohmann::json& json)
{
    try {
        user_id = json.at("user_id");
        action_id = json.at("action_id");
        qty = json.at("qty");
    }
    catch (...) {
        throw Error("Failed to parse user action data.");
    }
}
