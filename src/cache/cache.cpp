//
// AUGMENTS
//
// Copyright 2022 Christopher Borsellino
// All rights reserved.
//

#include "cache.h"

void Cache::init(const nlohmann::json& json)
{
    // Actions
    actions.clear();
    for (const auto& obj : json.at("actions"))
        actions.emplace_back(obj);

    // Actionsets
    actionsets.fill({});
    for (const auto& obj : json.at("actionsets"))
        actionsets.at(obj.at("species_id")).push_back(obj.at("action_id"));

    skills.clear();
    for (const auto& obj : json.at("skills"))
        skills.emplace_back(obj);

    // Skills
    skills.clear();
    for (const auto& obj : json.at("skills"))
        skills.emplace_back(obj);

    // Skillsets
    skillsets.fill({});
    for (const auto& obj : json.at("skillsets"))
        skillsets.at(obj.at("species_id")).push_back(obj.at("skill_id"));

    // Species
    species.clear();
    for (const auto& obj : json.at("species"))
        species.emplace_back(obj);

    // User
    user = User(json.at("user"));

    // User actions
    user_actions.fill(0);
    for (const auto& obj : json.at("user_actions"))
        user_actions.at(obj.at("action_id")) = obj.at("qty");

    // User skills
    user_skills.fill(0);
    for (const auto& obj : json.at("user_skills"))
        user_skills.at(obj.at("skill_id")) = obj.at("qty");

    // Staffs
    staffs.clear();
    for (const auto& obj : json.at("staffs"))
        staffs.emplace_back(obj);

    // Creatures
    creatures.clear();
    for (const auto& obj : json.at("creatures"))
        creatures.emplace_back(obj);
}

const Action& Cache::get_action(ActionID id) const
{
    return actions.at(id);
}

const Skill& Cache::get_skill(SkillID id) const
{
    return skills.at(id);
}

const Species& Cache::get_species(SpeciesID id) const
{
    return species.at(id);
}

const std::vector<ActionID>& Cache::get_actionset(SpeciesID species_id) const
{
    return actionsets.at(species_id);
}

const std::vector<SkillID>& Cache::get_skillset(SpeciesID species_id) const
{
    return skillsets.at(species_id);
}
