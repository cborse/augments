//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include "cache/augment.h"
#include "widgets/widget_container.h"

class AugmentInfo {
public:
    explicit AugmentInfo(const Renderer& renderer);

    void draw() const;
    void set_augment(const Augment* augment);

private:
    void refresh();

    const Augment* augment = nullptr;
    const Renderer& renderer;
    WidgetContainer widgets;
};
