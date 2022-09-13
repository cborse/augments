#pragma once

#include "scene.h"

class TeamScene : public Scene {
public:
    TeamScene(Game& game, const Augment* augment = nullptr);

    virtual void pause() override {}
    virtual void unpause() override;
    virtual void handle_event(const SDL_Event& e) override;
    virtual void update() override;
    virtual void draw() const override;

private:
    enum class StorageSort { alpha, level, };

    void refresh_data();
    void refresh_widgets();
    void refresh_list_widgets();
    void refresh_grid_widgets();
    void refresh_summary_widgets();
    void refresh_staff_widgets();
    void refresh_storage_widgets();
    void refresh_control_widgets();
    void refresh_augment_widgets();
    void animate_pair();

    void click_staff_left();
    void click_staff_right();
    void click_storage_left();
    void click_storage_right();
    void click_storage_sort();
    void click_list(int i);
    void click_grid(int i);

    Creature* get_selected_creature() const;
    int get_page_size() const;
    bool can_learn(const Creature& creature, const Action& action) const;
    bool can_learn(const Creature& creature, const Skill& skill) const;
    int get_needed_egg_wins(const Species& species) const;

    void assign();
    void unassign();
    void hatch();
    void use_augment();
    void use_augment2();

    int index = 8;
    int staff = 0;
    int page = 0;
    StorageSort sort = StorageSort::alpha;
    const Augment* augment = nullptr;

    std::vector<Creature*> eggs;
    std::vector<Creature*> storage;
    std::vector<Creature*> staff_creatures;

    static constexpr int max_creatures_per_staff = 7;
};
