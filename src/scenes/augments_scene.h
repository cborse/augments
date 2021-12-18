//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include "scene.h"
#include "augment_info.h"

class AugmentsScene : public Scene {
public:
    explicit AugmentsScene(Game& game);

    virtual void resume() override;
    virtual void handle_event(const SDL_Event& e) override;
    virtual void update() override;
    virtual void draw() const override;

private:
    void refresh_data();
    void refresh_widgets();
    void refresh_list_widgets();
    void refresh_page_widgets();
    void refresh_control_widgets();

    void click_list(int i);
    void click_page_left();
    void click_page_right();

    const Augment* get_selected_augment() const;
    int get_page_size() const;

    void use();

    int index = 0;
    int page = 0;
    AugmentInfo info;
    std::vector<Augment> augments;
};
