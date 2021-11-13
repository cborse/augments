//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include "game.h"
#include "widgets/widget_container.h"

class Scene {
public:
    virtual ~Scene() = default;

    virtual void handle_event(const SDL_Event& e) = 0;
    virtual void update() = 0;
    virtual void draw() const = 0;

protected:
    explicit Scene(Game& game) : game(game), widgets(game.renderer) {}

    Game& game;
    WidgetContainer widgets;
};
