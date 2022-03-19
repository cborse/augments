//
// AUGMENTS
//
// Copyright 2022 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include "graphics/renderer.h"

class Widget {
public:
    virtual ~Widget() = default;

    virtual bool handle_event(const SDL_Event& e) = 0;
    virtual void update() = 0;
    virtual void draw() const = 0;

protected:
    explicit Widget(const Renderer& renderer) : renderer(renderer) {}

    const Renderer& renderer;
};
