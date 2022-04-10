#pragma once

#include <map>
#include <vector>
#include "cache/enums.h"
#include "renderer.h"

class TextureContainer {
public:
    explicit TextureContainer(const Renderer& renderer);

    const Texture& get_general(const std::string& id) const;
    const Texture& get_species(SpeciesID id) const;
    const Texture& get_species_icon(SpeciesID id) const;
    const Texture& get_egg(RarityID rarity) const;
    const Texture& get_egg_icon(RarityID rarity) const;
    const Texture& get_hatch_animation(RarityID rarity) const;
    const Texture& get_type(TypeID type) const;
    const Texture& get_action_augment(TypeID type) const;
    const Texture& get_skill_augment() const;

private:
    std::map<std::string, Texture> general;
    std::vector<Texture> species;
    std::vector<Texture> species_icons;
    std::vector<Texture> eggs;
    std::vector<Texture> egg_icons;
    std::vector<Texture> hatch_animations;
    std::vector<Texture> types;
    std::vector<Texture> augments;
};
