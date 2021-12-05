//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
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
    actionsets.clear();
    for (const auto& obj : json.at("actionsets"))
        actionsets.emplace_back(obj);

    skills.clear();
    for (const auto& obj : json.at("skills"))
        skills.emplace_back(obj);

    // Series
    series.clear();
    for (const auto& obj : json.at("series"))
        series.emplace_back(obj);

    // Skills
    skills.clear();
    for (const auto& obj : json.at("skills"))
        skills.emplace_back(obj);

    // Skillsets
    skillsets.clear();
    for (const auto& obj : json.at("skillsets"))
        skillsets.emplace_back(obj);

    // Species
    species.clear();
    for (const auto& obj : json.at("species"))
        species.emplace_back(obj);

    // User
    user = User(json.at("user"));

    // User actions
    user_actions.clear();
    for (const auto& obj : json.at("user_actions"))
        user_actions.emplace_back(obj);

    // User skills
    user_skills.clear();
    for (const auto& obj : json.at("user_skills"))
        user_skills.emplace_back(obj);

    // Staffs
    staffs.clear();
    for (const auto& obj : json.at("staffs"))
        staffs.emplace_back(obj);

    // Creatures
    creatures.clear();
    for (const auto& obj : json.at("creatures"))
        creatures.emplace_back(obj);
}

const Action& Cache::get_action(uint32_t id) const
{
    return actions.at(id);
}

const Skill& Cache::get_skill(uint32_t id) const
{
    return skills.at(id);
}

const Species& Cache::get_species(uint32_t id) const
{
    return species.at(id);
}

uint8_t Cache::get_user_action_qty(uint32_t id) const
{
    auto lambda = [&id](const UserAction& user_action) {
        return user_action.action_id == id;
    };

    auto it = std::find_if(user_actions.begin(), user_actions.end(), lambda);
    if (it != user_actions.end())
        return it->qty;

    return 0;
}

uint8_t Cache::get_user_skill_qty(uint32_t id) const
{
    auto lambda = [&id](const UserSkill& user_skill) {
        return user_skill.skill_id == id;
    };

    auto it = std::find_if(user_skills.begin(), user_skills.end(), lambda);
    if (it != user_skills.end())
        return it->qty;

    return 0;
}

bool Cache::can_learn(const Creature& creature, const Action& action) const
{
    if (creature.egg)
        return false;

    const Species& species = get_species(creature.species_id);
    if (action.core && (action.type == species.type1 || action.type == species.type2) || action.type == species.type3)
        return true;

    auto lambda = [&creature, &action](const Actionset& actionset) {
        return actionset.species_id == creature.species_id && actionset.action_id == action.id;
    };
    return std::find_if(actionsets.begin(), actionsets.end(), lambda) != actionsets.end();
}
