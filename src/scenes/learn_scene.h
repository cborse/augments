#pragma once

#include "scene.h"
#include "augment_info.h"

class LearnScene : public Scene {
public:
    LearnScene(Game& game, const Augment& augment, Creature& creature);

    virtual void pause() override {}
    virtual void unpause() override {}
    virtual void handle_event(const SDL_Event& e) override;
    virtual void update() override;
    virtual void draw() const override;

private:
    void refresh_widgets();
    void refresh_list_widgets();
    void refresh_control_widgets();

    void click_list(int i);

    void replace();

    int index = 0;
    AugmentInfo info;
    const Augment& augment;
    Creature& creature;
};
