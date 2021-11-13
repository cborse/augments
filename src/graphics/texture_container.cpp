//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#include "texture_container.h"
#include "renderer.h"

// ************** TEMP
#include <filesystem>
#include <set>
// **************

const Texture& TextureContainer::get_general(const std::string& id) const
{
    return general.at(id);
}

const Texture& TextureContainer::get_species(uint32_t id) const
{
    return species.at((size_t)id * 6);
}

const Texture& TextureContainer::get_species_icon(uint32_t id) const
{
    return species_icons.at((size_t)id * 6);
}

const Texture& TextureContainer::get_egg(Rarity rarity) const
{
    return eggs.at((size_t)rarity);
}

const Texture& TextureContainer::get_egg_icon(Rarity rarity) const
{
    return egg_icons.at((size_t)rarity);
}

const Texture& TextureContainer::get_hatch_animation(Rarity rarity) const
{
    return hatch_animations.at((size_t)rarity);
}

const Texture& TextureContainer::get_type(Type type) const
{
    return types.at((size_t)type);
}

const Texture& TextureContainer::get_action(Type type) const
{
    return actions.at((size_t)type);
}

void TextureContainer::load(const Renderer& renderer)
{
    // General
    general.emplace(std::make_pair("cursor", renderer.load_texture("assets/general/cursor.png")));
    general.emplace(std::make_pair("mouse_left", renderer.load_texture("assets/general/mouse_left.png")));
    general.emplace(std::make_pair("mouse_right", renderer.load_texture("assets/general/mouse_right.png")));
    general.emplace(std::make_pair("staff", renderer.load_texture("assets/general/staff.png")));
    general.emplace(std::make_pair("assigned", renderer.load_texture("assets/general/assigned.png")));
    general.emplace(std::make_pair("alphacentauri", renderer.load_texture("assets/general/alphacentauri.png")));
    general.emplace(std::make_pair("button", renderer.load_texture("assets/general/button.png")));
    general.emplace(std::make_pair("button_hovered", renderer.load_texture("assets/general/button_hovered.png")));
    general.emplace(std::make_pair("window", renderer.load_texture("assets/general/window.png")));
    general.emplace(std::make_pair("frame", renderer.load_texture("assets/general/frame.png")));
    general.emplace(std::make_pair("cell", renderer.load_texture("assets/general/cell.png")));
    general.emplace(std::make_pair("cell_active", renderer.load_texture("assets/general/cell_active.png")));
    general.emplace(std::make_pair("level", renderer.load_texture("assets/general/level.png")));
    general.emplace(std::make_pair("xp", renderer.load_texture("assets/general/xp.png")));

    // Eggs
    eggs.emplace_back(renderer.load_texture("assets/eggs/egg_common.png"));
    eggs.emplace_back(renderer.load_texture("assets/eggs/egg_uncommon.png"));
    eggs.emplace_back(renderer.load_texture("assets/eggs/egg_rare.png"));

    egg_icons.emplace_back(renderer.load_texture("assets/eggs/egg_icon_common.png"));
    egg_icons.emplace_back(renderer.load_texture("assets/eggs/egg_icon_uncommon.png"));
    egg_icons.emplace_back(renderer.load_texture("assets/eggs/egg_icon_rare.png"));

    hatch_animations.emplace_back(renderer.load_texture("assets/eggs/hatch_common.png"));
    hatch_animations.emplace_back(renderer.load_texture("assets/eggs/hatch_uncommon.png"));
    hatch_animations.emplace_back(renderer.load_texture("assets/eggs/hatch_rare.png"));

    // Creatures
    for (int i = 0; i < 6; i++) {
        // none
        species.emplace_back();
        species_icons.emplace_back();
    }

    std::set<std::string> files;
    namespace fs = std::filesystem;
    for (const auto& folder1 : fs::directory_iterator("assets/creatures")) {
        for (const auto& folder2 : fs::directory_iterator(folder1.path())) {
            if (folder2.path().string().find("MACOSX") != std::string::npos)
                continue;

            for (const auto& file : fs::directory_iterator(folder2.path())) {
                std::string name = file.path().string();
                if (!name.ends_with(".DS_Store"))
                    files.emplace(name);
            }
        }
    }

    for (const auto& file : files) {
        if (file.find("Mini") != file.npos)
            species_icons.emplace_back(renderer.load_texture(file));
        else
            species.emplace_back(renderer.load_texture(file));
    }

    //// Types
    //types.emplace_back(); // none
    //types.emplace_back(renderer.load_texture("types/type_earth.png"));
    //types.emplace_back(renderer.load_texture("types/type_water.png"));
    //types.emplace_back(renderer.load_texture("types/type_ice.png"));
    //types.emplace_back(renderer.load_texture("types/type_fire.png"));
    //types.emplace_back(renderer.load_texture("types/type_chemical.png"));
    //types.emplace_back(renderer.load_texture("types/type_solar.png"));
    //types.emplace_back(renderer.load_texture("types/type_strength.png"));
    //types.emplace_back(renderer.load_texture("types/type_psyche.png"));
    //types.emplace_back(renderer.load_texture("types/type_wind.png"));
    //types.emplace_back(renderer.load_texture("types/type_metal.png"));
    //types.emplace_back(renderer.load_texture("types/type_electric.png"));
    //types.emplace_back(renderer.load_texture("types/type_spirit.png"));

    //// Actions
    //actions.emplace_back(); // none
    //actions.emplace_back(renderer.load_texture("actions/action_earth.png"));
    //actions.emplace_back(renderer.load_texture("actions/action_water.png"));
    //actions.emplace_back(renderer.load_texture("actions/action_ice.png"));
    //actions.emplace_back(renderer.load_texture("actions/action_fire.png"));
    //actions.emplace_back(renderer.load_texture("actions/action_chemical.png"));
    //actions.emplace_back(renderer.load_texture("actions/action_solar.png"));
    //actions.emplace_back(renderer.load_texture("actions/action_strength.png"));
    //actions.emplace_back(renderer.load_texture("actions/action_psyche.png"));
    //actions.emplace_back(renderer.load_texture("actions/action_wind.png"));
    //actions.emplace_back(renderer.load_texture("actions/action_metal.png"));
    //actions.emplace_back(renderer.load_texture("actions/action_electric.png"));
    //actions.emplace_back(renderer.load_texture("actions/action_spirit.png"));

    //// Skills
    //skills.emplace_back(renderer.load_texture("skills/skill_accuracy.png"));
    //skills.emplace_back(renderer.load_texture("skills/skill_actions.png"));
    //skills.emplace_back(renderer.load_texture("skills/skill_contact.png"));
    //skills.emplace_back(renderer.load_texture("skills/skill_detection.png"));
    //skills.emplace_back(renderer.load_texture("skills/skill_effectivity.png"));
    //skills.emplace_back(renderer.load_texture("skills/skill_elimination.png"));
    //skills.emplace_back(renderer.load_texture("skills/skill_energy.png"));
    //skills.emplace_back(renderer.load_texture("skills/skill_health.png"));
    //skills.emplace_back(renderer.load_texture("skills/skill_movement.png"));
    //skills.emplace_back(renderer.load_texture("skills/skill_special.png"));
    //skills.emplace_back(renderer.load_texture("skills/skill_stats.png"));
    //skills.emplace_back(renderer.load_texture("skills/skill_trick.png"));
    //skills.emplace_back(renderer.load_texture("skills/skill_types.png"));
    //skills.emplace_back(renderer.load_texture("skills/skill_visibility.png"));
}
