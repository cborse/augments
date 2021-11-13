//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include "widget.h"

class Image : public Widget {
public:
    enum AnimType {
        anim_type_none,
        anim_type_frame,
        anim_type_bounce,
        anim_type_shake,
    };

    explicit Image(const Renderer& renderer) : Widget(renderer) {}

    virtual bool handle_event(const SDL_Event& e) override;
    virtual void update() override;
    virtual void draw() const override;

    bool is_anim_finished() const;

    void set_alpha(uint8_t alpha);
    void set_anim_frame_count(int frame_count);
    void set_anim_frame_size(const SDL_Point& size);
    void set_anim_type(AnimType type);
    void set_position(const SDL_Point& position);
    void set_texture(const Texture& texture);
    void set_visibility(bool visible);

    Image& with_alpha(uint8_t alpha);
    Image& with_anim_frame_count(int count);
    Image& with_anim_frame_size(const SDL_Point& size);
    Image& with_anim_type(AnimType type);
    Image& with_position(const SDL_Point& position);
    Image& with_texture(const Texture& texture);
    Image& with_visibility(bool visible);

private:
    bool visible = true;
    uint8_t alpha = 255;
    SDL_Point position = {};
    const Texture* texture = nullptr;

    // Animation stuff
    AnimType anim_type = anim_type_none;
    int anim_counter = 0;
    int anim_current_frame = 0;
    int anim_frame_count = 0;
    SDL_Point anim_offset = {};
    SDL_Point anim_frame_size = {};
    double anim_angle = 0.0;

    static constexpr int anim_speed_factor = 12;
};
