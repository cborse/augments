//
// AUGMENTS
//
// Copyright 2022 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include "cache/augment.h"
#include "widgets/widget_container.h"

class AugmentInfo {
public:
    explicit AugmentInfo(const Renderer& renderer);

    void draw() const;
    void set_augment(const Action& action);
    void set_augment(const Skill& skill);

private:
    void refresh();

    const Action* action = nullptr;
    const Skill* skill = nullptr;
    const Renderer& renderer;
    WidgetContainer widgets;
};
