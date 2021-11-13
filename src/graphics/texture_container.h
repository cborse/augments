//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include <map>
#include <string>
#include <vector>
#include "texture.h"
#include "cache/enums.h"

class Renderer;

class TextureContainer {
public:
    void load(const class Renderer& renderer);

    const Texture& get_general(const std::string& id) const;
    const Texture& get_species(uint32_t id) const;
    const Texture& get_species_icon(uint32_t id) const;
    const Texture& get_egg(Rarity rarity) const;
    const Texture& get_egg_icon(Rarity rarity) const;
    const Texture& get_hatch_animation(Rarity rarity) const;
    const Texture& get_type(Type type) const;
    const Texture& get_action(Type type) const;
    //const Texture& get_skill(Skill_type type) const;

private:
    std::map<std::string, Texture> general;
    std::vector<Texture> species;
    std::vector<Texture> species_icons;
    std::vector<Texture> eggs;
    std::vector<Texture> egg_icons;
    std::vector<Texture> hatch_animations;
    std::vector<Texture> types;
    std::vector<Texture> actions;
    std::vector<Texture> skills;
};
