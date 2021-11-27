//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include "scene.h"

class TeamScene : public Scene {
public:
    TeamScene(Game& game);

    virtual void handle_event(const SDL_Event& e) override;
    virtual void update() override;
    virtual void draw() const override;

private:
    void refresh_data();

    void refresh_widgets();
    void refresh_list_widgets();
    void refresh_grid_widgets();
    void refresh_summary_widgets();
    void refresh_staff_widgets();
    void refresh_page_widgets();
    void refresh_control_widgets();

    void click_staff_left();
    void click_staff_right();
    void click_storage_left();
    void click_storage_right();
    void click_list(int i);
    void click_grid(int i);

    Creature* get_selected_creature() const;

    void assign();
    void unassign();
    void hatch();

    int index = 8;
    int staff = 0;
    int page = 0;

    std::vector<Creature*> eggs;
    std::vector<Creature*> storage;
    std::vector<std::vector<Creature*>> staff_creatures;
};
