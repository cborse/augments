//
// AUGMENTS
//
// Copyright 2022 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include "scene.h"

class MenuScene : public Scene {
public:
    explicit MenuScene(Game& game);

    virtual void resume() override {}
    virtual void handle_event(const SDL_Event& e) override;
    virtual void update() override;
    virtual void draw() const override;
};
