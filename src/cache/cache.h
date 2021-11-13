//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include "creature.h"
#include "species.h"
#include "staff.h"
#include "user.h"

class Cache {
public:
    void init(const nlohmann::json& json);

    const Species& get_species(uint32_t id) const;

    User user;
    std::vector<Staff> staffs;
    std::vector<Creature> creatures;

private:
    std::vector<Species> species;
};
