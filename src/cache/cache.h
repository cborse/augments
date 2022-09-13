#pragma once

#include <variant>
#include "action.h"
#include "creature.h"
#include "enums.h"
#include "skill.h"
#include "species.h"
#include "staff.h"
#include "user.h"
#include "nlohmann/json_fwd.hpp"

typedef std::variant<Action, Skill> Augment;

class Cache {
public:
    void init(const nlohmann::json& json);

    const Action& get_action(ActionID id) const;
    const Skill& get_skill(SkillID id) const;
    const Species& get_species(SpeciesID id) const;

    User user;
    std::vector<Staff> staffs;
    std::vector<Creature> creatures;
    uint8_t user_actions[ACTION_COUNT];
    uint8_t user_skills[SKILL_COUNT];

private:
    static const Action actions[ACTION_COUNT];
    static const Skill skills[SKILL_COUNT];
    static const Species species[SPECIES_COUNT];
};
