//
// AUGMENTS
//
// Copyright 2022 Christopher Borsellino
// All rights reserved.
//

#include "button.h"

Button::Button(const Renderer& renderer) : Widget(renderer), label(renderer)
{
    label.set_color({ 243, 239, 225 });
    label.set_shadow(true);
}

bool Button::handle_event(const SDL_Event& e)
{
    if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT && visible && hovered) {
        action();
        return true;
    }

    return false;
}

void Button::update()
{
    hovered = SDL_PointInRect(&renderer.get_mouse(), &bounds);
}

void Button::draw() const
{
    if (visible) {
        const TextureContainer& textures = renderer.get_textures();
        if (hovered)
            renderer.draw_border(bounds, textures.get_general("button_hovered"), { 44, 44, 40 });
        else
            renderer.draw_border(bounds, textures.get_general("button"), { 44, 44, 40 });
        label.draw();
    }
}

void Button::set_action(std::function<void()> action)
{
    this->action = action;
}

void Button::set_bounds(const SDL_Rect& bounds)
{
    this->bounds = bounds;
    center_label();
}

void Button::set_string(const std::string& string)
{
    label.set_string(string);
    center_label();
}

void Button::set_visibility(bool visible)
{
    this->visible = visible;
}

Button& Button::with_action(std::function<void()> action)
{
    set_action(action);
    return *this;
}

Button& Button::with_bounds(const SDL_Rect& bounds)
{
    set_bounds(bounds);
    return *this;
}

Button& Button::with_string(const std::string& string)
{
    set_string(string);
    return *this;
}

Button& Button::with_visibility(bool visible)
{
    set_visibility(visible);
    return *this;
}

void Button::center_label()
{
    int label_width = label.get_size().x;
    label.set_position({ bounds.x + (bounds.w - label_width) / 2, bounds.y + 5 });
}
