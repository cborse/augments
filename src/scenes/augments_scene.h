//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include "scene.h"

class AugmentsScene : public Scene {
public:
    explicit AugmentsScene(Game& game);

    virtual void handle_event(const SDL_Event& e) override;
    virtual void update() override;
    virtual void draw() const override;

private:
    void refresh_data();
    void refresh_widgets();
    void click_list(int i);
    void click_page_left();
    void click_page_right();

    void use();

    int index = 0;
    int page = 0;

    std::vector<Augment> augments;
};
