//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#include "image.h"

bool Image::handle_event(const SDL_Event& e)
{
    return false;
}

void Image::update()
{
    switch (anim_type) {
    case anim_type_frame:
        if (anim_counter < anim_frame_count * anim_speed_factor - 1) {
            anim_counter++;
            if (anim_counter % anim_speed_factor == 0)
                anim_current_frame++;
        }
        break;

    case anim_type_bounce:
        if (anim_counter < anim_speed_factor * 1)
            anim_offset.y = -1;
        else if (anim_counter < anim_speed_factor * 2)
            anim_offset.y = 0;
        else
            anim_counter = 1;
        anim_counter++;
        break;

    case anim_type_shake:
        if (anim_counter < anim_speed_factor * 1)
            anim_angle = -4.0;
        else if (anim_counter < anim_speed_factor * 2)
            anim_angle = 0.0;
        else if (anim_counter < anim_speed_factor * 3)
            anim_angle = 4.0;
        else if (anim_counter < anim_speed_factor * 6)
            anim_angle = 0.0;
        else
            anim_counter = 1;
        anim_counter++;
        break;

    default:
        break;
    }
}

void Image::draw() const
{
    if (visible && texture) {
        if (alpha < 255)
            texture->set_alpha(alpha);

        switch (anim_type) {
        case anim_type_frame:
            renderer.draw_sub(*texture, position,
                              { 0, (anim_current_frame % anim_frame_count) * anim_frame_size.y,
                              anim_frame_size.x, anim_frame_size.y });
            break;

        case anim_type_bounce:
            renderer.draw(*texture, { position.x + anim_offset.x, position.y + anim_offset.y });
            break;

        case anim_type_shake:
            renderer.draw_angle(*texture, position, anim_angle);
            break;

        default:
            renderer.draw(*texture, position);
            break;
        }

        if (alpha < 255)
            texture->set_alpha(255);
    }
}

bool Image::is_anim_finished() const
{
    return anim_counter == anim_frame_count * anim_speed_factor - 1;
}

void Image::set_alpha(uint8_t alpha)
{
    this->alpha = alpha;
}

void Image::set_anim_frame_count(int frame_count)
{
    anim_frame_count = frame_count;
}

void Image::set_anim_frame_size(const SDL_Point& size)
{
    anim_frame_size = size;
}

void Image::set_anim_type(AnimType type)
{
    if (anim_type != type) {
        anim_type = type;
        anim_counter = 0;
        anim_current_frame = 0;
        anim_offset = {};
        anim_angle = 0.0;
    }
}

void Image::set_position(const SDL_Point& position)
{
    this->position = position;
}

void Image::set_texture(const Texture& texture)
{
    this->texture = &texture;
}

void Image::set_visibility(bool visible)
{
    this->visible = visible;
}

Image& Image::with_alpha(uint8_t alpha)
{
    set_alpha(alpha);
    return *this;
}

Image& Image::with_anim_frame_count(int count)
{
    set_anim_frame_count(count);
    return *this;
}

Image& Image::with_anim_frame_size(const SDL_Point& size)
{
    set_anim_frame_size(size);
    return *this;
}

Image& Image::with_anim_type(AnimType type)
{
    set_anim_type(type);
    return *this;
}

Image& Image::with_position(const SDL_Point& position)
{
    set_position(position);
    return *this;
}

Image& Image::with_texture(const Texture& texture)
{
    set_texture(texture);
    return *this;
}

Image& Image::with_visibility(bool visible)
{
    set_visibility(visible);
    return *this;
}
