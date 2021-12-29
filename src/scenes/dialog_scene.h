//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include <steam/steam_api.h>
#include "scene.h"

class DialogScene : public Scene {
public:
    explicit DialogScene(Game& game);

    virtual void resume() override {}
    virtual void handle_event(const SDL_Event& e) override;
    virtual void update() override;
    virtual void draw() const override;

    void add_line(const std::string& line);
    void add_choice(const std::string& string, std::function<void()> action);

private:
    int num_lines = 0;
    int num_choices = 0;
};
