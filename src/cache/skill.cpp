//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#include "skill.h"
#include "error.h"

Skill::Skill(const nlohmann::json& json)
{
    try {
        id = json.at("id");
        name = json.at("name");
        core = json.at("core");
        desc1 = json.at("desc1");
        desc2 = json.at("desc2");
        desc3 = json.at("desc3");
    }
    catch (...) {
        throw Error("Failed to parse skill data.");
    }
}
