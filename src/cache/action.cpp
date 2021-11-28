//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#include "action.h"
#include "error.h"

Action::Action(const nlohmann::json& json)
{
    try {
        id = json.at("id");
        name = json.at("name");
        type = json.at("type");
        core = json.at("core");
        effect = json.at("effect");
        effect_chance = json.at("effect_chance");
        cover = json.at("cover");
        style = json.at("style");
        detect = json.at("detect");
        power = json.at("power");
        speed = json.at("speed");
        energy = json.at("energy");
        accuracy = json.at("accuracy");
        contact = json.at("contact");
        move = json.at("move");
        desc1 = json.at("desc1");
        desc2 = json.at("desc2");
        desc3 = json.at("desc3");
    }
    catch (...) {
        throw Error("Failed to parse action data.");
    }
}

std::string Action::get_cover_string(uint8_t cover)
{
    static const std::vector<std::string> covers = {
        "-", "RING 1", "RING 2", "ARC 2",
        "ARC 3", "ARC 4", "ARC 5", "TILE 1",
        "TILE 2", "TILE 3", "TILE 4", "TILE 5",
        "LINE 2", "LINE 3", "LINE 4", "LINE 5"
    };

    return covers.at(cover);
}

std::string Action::get_style_string(uint8_t style)
{
    if (style == 1)
        return "INNER";
    else if (style == 2)
        return "OUTER";

    return "-";
}
