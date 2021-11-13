//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include "scene.h"

class HatchScene : public Scene {
public:
    HatchScene(Game& game, const Creature& creature);

    virtual void handle_event(const SDL_Event& e) override;
    virtual void update() override;
    virtual void draw() const override;

private:
    void start();
    void end();
    void back();

    bool animating = true;
    const Creature& creature;
};
