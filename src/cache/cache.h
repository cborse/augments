//
// AUGMENTS
//
// Copyright 2022 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include "action.h"
#include "creature.h"
#include "skill.h"
#include "species.h"
#include "staff.h"
#include "user.h"

class Cache {
public:
    void init(const nlohmann::json& json);

    const Action& get_action(ActionID id) const;
    const Skill& get_skill(SkillID id) const;
    const Species& get_species(SpeciesID id) const;
    const std::vector<ActionID>& get_actionset(SpeciesID species_id) const;
    const std::vector<SkillID>& get_skillset(SpeciesID species_id) const;

    User user;
    std::array<uint8_t, ACTION_COUNT> user_actions;
    std::array<uint8_t, SKILL_COUNT> user_skills;
    std::vector<Staff> staffs;
    std::vector<Creature> creatures;

private:
    std::vector<Action> actions;
    std::vector<Skill> skills;
    std::vector<Species> species;
    std::array<std::vector<ActionID>, SPECIES_COUNT> actionsets;
    std::array<std::vector<SkillID>, SPECIES_COUNT> skillsets;
};
