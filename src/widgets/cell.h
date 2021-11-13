//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include <functional>
#include "image.h"
#include "label.h"

class Cell : public Widget {
public:
    explicit Cell(const Renderer& renderer);

    virtual bool handle_event(const SDL_Event& e) override;
    virtual void update() override {}
    virtual void draw() const override;

    void set_action(std::function<void()> action);
    void set_active(bool active);
    void set_bounds(const SDL_Rect& bounds);
    void set_image_offset(const SDL_Point& offset);
    void set_string(const std::string& string);
    void set_texture(const Texture& texture);
    void set_visibility(bool visible);

    Cell& with_action(std::function<void()> action);
    Cell& with_bounds(const SDL_Rect& bounds);
    Cell& with_image_offset(const SDL_Point& offset);
    Cell& with_string(const std::string& string);
    Cell& with_texture(const Texture& texture);
    Cell& with_visibility(bool visible);

private:
    bool visible = true;
    bool active = false;
    SDL_Rect bounds = {};
    std::function<void()> action = [] {};
    Image image;
    Label label;
};
