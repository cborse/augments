//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include <variant>
#include "action.h"
#include "skill.h"

typedef std::variant<Action, Skill> Augment;
