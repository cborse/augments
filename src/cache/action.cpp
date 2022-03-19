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

std::string Action::get_cover_string(CoverID cover)
{
    switch (cover) {
    case COVER_RING1:
        return "RING 1";
    case COVER_RING2:
        return "RING 2";
    case COVER_ARC2:
        return "ARC 2";
    case COVER_ARC3:
        return "ARC 3";
    case COVER_ARC4:
        return "ARC 4";
    case COVER_ARC5:
        return "ARC 5";
    case COVER_TILE1:
        return "TILE 1";
    case COVER_TILE2:
        return "TILE 2";
    case COVER_TILE3:
        return "TILE 3";
    case COVER_TILE4:
        return "TILE 4";
    case COVER_TILE5:
        return "TILE 5";
    case COVER_LINE2:
        return "LINE 2";
    case COVER_LINE3:
        return "LINE 3";
    case COVER_LINE4:
        return "LINE 4";
    case COVER_LINE5:
        return "LINE 5";
    case COVER_NONE:
    default:
        return "-";
    }
}

std::string Action::get_style_string(StyleID style)
{
    switch (style) {
    case STYLE_INNER:
        return "INNER";
    case STYLE_OUTER:
        return "OUTER";
    case STYLE_NONE:
    default:
        return "-";
    }
}
