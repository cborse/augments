#pragma once

#include <functional>
#include "label.h"

class Button : public Widget {
public:
    Button(const Renderer& renderer, const TextureContainer& textures);

    virtual bool handle_event(const SDL_Event& e) override;
    virtual void update() override {}
    virtual void draw() const override;

    void set_action(std::function<void()> action);
    void set_bounds(const SDL_Rect& bounds);
    void set_string(const std::string& string);
    void set_visibility(bool visible);

    Button& with_action(std::function<void()> action);
    Button& with_bounds(const SDL_Rect& bounds);
    Button& with_string(const std::string& string);
    Button& with_visibility(bool visible);

private:
    void center_label();

    bool visible = true;
    bool hovered = false;
    SDL_Rect bounds = {};
    std::function<void()> action = [] {};
    Label label;
};
