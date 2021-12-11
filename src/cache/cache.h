//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include "action.h"
#include "actionset.h"
#include "creature.h"
#include "series.h"
#include "skill.h"
#include "skillset.h"
#include "species.h"
#include "staff.h"
#include "user.h"
#include "user_action.h"
#include "user_skill.h"

class Cache {
public:
    void init(const nlohmann::json& json);

    const Action& get_action(uint32_t id) const;
    const Skill& get_skill(uint32_t id) const;
    const Species& get_species(uint32_t id) const;

    // Helpers
    uint8_t get_quantity(const Action& action) const;
    uint8_t get_quantity(const Skill& skill) const;
    bool can_learn(const Creature& creature, const Action& action) const;
    bool can_learn(const Creature& creature, const Skill& skill) const;

    User user;
    std::vector<UserAction> user_actions;
    std::vector<UserSkill> user_skills;
    std::vector<Staff> staffs;
    std::vector<Creature> creatures;

private:
    std::vector<Action> actions;
    std::vector<Actionset> actionsets;
    std::vector<Skill> skills;
    std::vector<Skillset> skillsets;
    std::vector<Series> series;
    std::vector<Species> species;
};
