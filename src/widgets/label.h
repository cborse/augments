//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include "widget.h"

class Label : public Widget {
public:
    enum Align {
        left,
        center,
        right,
    };

    explicit Label(const Renderer& renderer) : Widget(renderer) {}

    virtual bool handle_event(const SDL_Event& e) override;
    virtual void update() override {}
    virtual void draw() const override;

    const SDL_Point& get_size() const;

    void set_alignment(Align align);
    void set_alpha(uint8_t alpha);
    void set_color(const SDL_Color& color);
    void set_position(const SDL_Point& position);
    void set_shadow(bool shadow);
    void set_string(const std::string& string);
    void set_visibility(bool visible);

    Label& with_alignment(Align align);
    Label& with_alpha(uint8_t alpha);
    Label& with_color(const SDL_Color& color);
    Label& with_position(const SDL_Point& position);
    Label& with_shadow(bool shadow);
    Label& with_string(const std::string& string);
    Label& with_visibility(bool visible);

private:
    void update_texture();

    bool visible = true;
    bool shadow = true;
    Align alignment = left;
    uint8_t alpha = 255;
    std::string string;
    SDL_Color color = {};
    SDL_Point position = {};
    Texture texture;
    Texture texture_shadow;
};
