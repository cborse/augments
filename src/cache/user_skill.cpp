//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#include "user_skill.h"
#include "error.h"

UserSkill::UserSkill(const nlohmann::json& json)
{
    try {
        user_id = json.at("user_id");
        skill_id = json.at("skill_id");
        qty = json.at("qty");
    }
    catch (...) {
        throw Error("Failed to parse user skill data.");
    }
}
