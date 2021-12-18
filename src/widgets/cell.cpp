//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#include "cell.h"

Cell::Cell(const Renderer& renderer)
    : Widget(renderer)
    , image(renderer)
    , label(renderer)
{
    label.set_color({ 243, 239, 225 });
}

bool Cell::handle_event(const SDL_Event& e)
{
    if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT && visible) {
        const SDL_Point mouse = { e.button.x, e.button.y };
        if (SDL_PointInRect(&mouse, &bounds)) {
            action();
            return true;
        }
    }

    return false;
}

void Cell::update()
{
    image.update();
}

void Cell::draw() const
{
    if (visible) {
        const TextureContainer& textures = renderer.get_textures();
        if (active)
            renderer.draw_border(bounds, textures.get_general("cell_active"), { 82, 81, 74 });
        else
            renderer.draw_border(bounds, textures.get_general("cell"), { 48, 48, 44 });

        if (content_visible) {
            image.draw();
            label.draw();
        }
    }
}

Image& Cell::get_image()
{
    return image;
}

Label& Cell::get_label()
{
    return label;
}

void Cell::set_action(std::function<void()> action)
{
    this->action = action;
}

void Cell::set_active(bool active)
{
    this->active = active;
}

void Cell::set_bounds(const SDL_Rect& bounds)
{
    this->bounds = bounds;

    if (align == Label::center) {
        label.set_alignment(Label::center);
        label.set_position({ bounds.x + bounds.w / 2, bounds.y + 6 });
    }
    else if (align == Label::right) {
        label.set_alignment(Label::right);
        label.set_position({ bounds.x + bounds.w - 4, bounds.y + 6 });
    }
    else {
        label.set_alignment(Label::left);
        label.set_position({ bounds.x + 4, bounds.y + 6 });
    }
}

void Cell::set_image_offset(const SDL_Point& offset)
{
    image.set_position({ bounds.x + offset.x, bounds.y + offset.y });
}

void Cell::set_label_alignment(Label::Align align)
{
    this->align = align;
    set_bounds(bounds);
}

void Cell::set_string(const std::string& string)
{
    label.set_string(string);
    set_bounds(bounds);
}

void Cell::set_texture(const Texture& texture)
{
    image.set_texture(texture);
}

void Cell::set_visibility(bool visible)
{
    this->visible = visible;
}

void Cell::set_content_visibility(bool visible)
{
    content_visible = visible;
}

Cell& Cell::with_action(std::function<void()> action)
{
    set_action(action);
    return *this;
}

Cell& Cell::with_bounds(const SDL_Rect& bounds)
{
    set_bounds(bounds);
    return *this;
}

Cell& Cell::with_image_offset(const SDL_Point& offset)
{
    set_image_offset(offset);
    return *this;
}

Cell& Cell::with_label_alignment(Label::Align align)
{
    set_label_alignment(align);
    return *this;
}

Cell& Cell::with_string(const std::string& string)
{
    set_string(string);
    return *this;
}

Cell& Cell::with_texture(const Texture& texture)
{
    set_texture(texture);
    return *this;
}

Cell& Cell::with_visibility(bool visible)
{
    set_visibility(visible);
    return *this;
}

Cell& Cell::with_content_visibility(bool visible)
{
    set_content_visibility(visible);
    return *this;
}
