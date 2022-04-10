#include "cache.h"

void Cache::init(const nlohmann::json& json)
{
    // User
    user.id = json.at("user").at("id");
    user.steam_id = json.at("user").at("steam_id");
    user.egg_cap = json.at("user").at("egg_cap");
    user.storage_pages = json.at("user").at("storage_pages");

    // Staffs
    staffs.clear();
    for (const auto& obj : json.at("staffs")) {
        Staff staff;
        staff.slot = obj.at("slot");
        staff.name = obj.at("name");
        staffs.push_back(staff);
    }

    // Creatures
    creatures.clear();
    for (const auto& obj : json.at("creatures")) {
        Creature creature;
        creature.id = obj.at("id");
        creature.species_id = obj.at("species_id");
        creature.staff_slot = obj.at("staff_slot");
        creature.name = obj.at("name");
        creature.egg = obj.at("egg");
        creature.xp = obj.at("xp");
        creature.wins = obj.at("wins");
        creature.actions[0] = obj.at("action1");
        creature.actions[1] = obj.at("action2");
        creature.actions[2] = obj.at("action3");
        creature.skills[0] = obj.at("skill1");
        creature.skills[1] = obj.at("skill2");
        creature.skills[2] = obj.at("skill3");
        creatures.push_back(creature);
    }

    // User actions
    memset(user_actions, 0, ACTION_COUNT);
    for (const auto& obj : json.at("user_actions"))
        user_actions[obj.at("action_id")] = obj.at("qty");

    // User skills
    memset(user_skills, 0, SKILL_COUNT);
    for (const auto& obj : json.at("user_skills"))
        user_skills[obj.at("skill_id")] = obj.at("qty");
}

const Action& Cache::get_action(ActionID id) const
{
    return actions[id];
}

const Skill& Cache::get_skill(SkillID id) const
{
    return skills[id];
}

const Species& Cache::get_species(SpeciesID id) const
{
    return species[id];
}
