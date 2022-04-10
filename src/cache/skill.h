#pragma once

#include <string>
#include "enums.h"

struct Skill {
    SkillID id;
    std::string name;
    bool core;
    std::string desc1;
    std::string desc2;
    std::string desc3;
};
