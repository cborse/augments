//
// AUGMENTS
//
// Copyright 2022 Christopher Borsellino
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

const Texture& TextureContainer::get_species(SpeciesID id) const
{
    return species.at(id * 6);
}

const Texture& TextureContainer::get_species_icon(SpeciesID id) const
{
    return species_icons.at(id * 6);
}

const Texture& TextureContainer::get_egg(RarityID rarity) const
{
    return eggs.at(rarity);
}

const Texture& TextureContainer::get_egg_icon(RarityID rarity) const
{
    return egg_icons.at(rarity);
}

const Texture& TextureContainer::get_hatch_animation(RarityID rarity) const
{
    return hatch_animations.at(rarity);
}

const Texture& TextureContainer::get_type(TypeID type) const
{
    return types.at(type);
}

const Texture& TextureContainer::get_augment(TypeID type) const
{
    return augments.at(type);
}

const Texture& TextureContainer::get_skill() const
{
    return augments.at(TYPE_ILLUSION + 1);
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

    // Types
    types.emplace_back(); // none
    types.emplace_back(renderer.load_texture("assets/types/Type Symbol Strength.png"));
    types.emplace_back(renderer.load_texture("assets/types/Type Symbol Ground.png"));
    types.emplace_back(renderer.load_texture("assets/types/Type Symbol Water.png"));
    types.emplace_back(renderer.load_texture("assets/types/Type Symbol Ice.png"));
    types.emplace_back(renderer.load_texture("assets/types/Type Symbol Chemical.png"));
    types.emplace_back(renderer.load_texture("assets/types/Type Symbol Metal.png"));
    types.emplace_back(renderer.load_texture("assets/types/Type Symbol Stone.png"));
    types.emplace_back(renderer.load_texture("assets/types/Type Symbol Solar.png"));
    types.emplace_back(renderer.load_texture("assets/types/Type Symbol Psyche.png"));
    types.emplace_back(renderer.load_texture("assets/types/Type Symbol Wind.png"));
    types.emplace_back(renderer.load_texture("assets/types/Type Symbol Electric.png"));
    types.emplace_back(renderer.load_texture("assets/types/Type Symbol Spirit.png"));
    types.emplace_back(renderer.load_texture("assets/types/Type Symbol Fire.png"));
    types.emplace_back(renderer.load_texture("assets/types/Type Symbol Illusion.png"));

    // Augments
    augments.emplace_back(); // none
    augments.emplace_back(renderer.load_texture("assets/augments/Action Augment Strength.png"));
    augments.emplace_back(renderer.load_texture("assets/augments/Action Augment Ground.png"));
    augments.emplace_back(renderer.load_texture("assets/augments/Action Augment Water.png"));
    augments.emplace_back(renderer.load_texture("assets/augments/Action Augment Ice.png"));
    augments.emplace_back(renderer.load_texture("assets/augments/Action Augment Chemical.png"));
    augments.emplace_back(renderer.load_texture("assets/augments/Action Augment Metal.png"));
    augments.emplace_back(renderer.load_texture("assets/augments/Action Augment Stone.png"));
    augments.emplace_back(renderer.load_texture("assets/augments/Action Augment Solar.png"));
    augments.emplace_back(renderer.load_texture("assets/augments/Action Augment Psyche.png"));
    augments.emplace_back(renderer.load_texture("assets/augments/Action Augment Wind.png"));
    augments.emplace_back(renderer.load_texture("assets/augments/Action Augment Electric.png"));
    augments.emplace_back(renderer.load_texture("assets/augments/Action Augment Spirit.png"));
    augments.emplace_back(renderer.load_texture("assets/augments/Action Augment Fire.png"));
    augments.emplace_back(renderer.load_texture("assets/augments/Action Augment Illusion.png"));
    augments.emplace_back(renderer.load_texture("assets/augments/Skill Augment.png"));
}
