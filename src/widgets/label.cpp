#include "label.h"
#include "label.h"

bool Label::handle_event(const SDL_Event& e)
{
    return false;
}

void Label::draw() const
{
    if (visible) {
        if (alpha < 255)
            texture.set_alpha(alpha);

        SDL_Point draw_position = position;

        if (alignment == Align::center)
            draw_position = { position.x - get_size().x / 2, position.y };
        else if (alignment == Align::right)
            draw_position = { position.x - get_size().x, position.y };

        if (shadow && alpha == 255)
            renderer.draw(texture_shadow, { draw_position.x, draw_position.y + 1 });

        renderer.draw(texture, draw_position);

        if (alpha < 255)
            texture.set_alpha(255);
    }
}

const SDL_Point& Label::get_size() const
{
    return texture.get_size();
}

void Label::set_alignment(Align align)
{
    alignment = align;
}

void Label::set_alpha(uint8_t alpha)
{
    this->alpha = alpha;
}

void Label::set_color(const SDL_Color& color)
{
    this->color = color;
    update_texture();
}

void Label::set_position(const SDL_Point& position)
{
    this->position = position;
}

void Label::set_shadow(bool shadow)
{
    this->shadow = shadow;
}

void Label::set_string(const std::string& string)
{
    this->string = string;
    update_texture();
}

void Label::set_visibility(bool visible)
{
    this->visible = visible;
}

Label& Label::with_alignment(Align align)
{
    set_alignment(align);
    return *this;
}

Label& Label::with_alpha(uint8_t alpha)
{
    set_alpha(alpha);
    return *this;
}

Label& Label::with_color(const SDL_Color& color)
{
    set_color(color);
    return *this;
}

Label& Label::with_position(const SDL_Point& position)
{
    set_position(position);
    return *this;
}

Label& Label::with_shadow(bool shadow)
{
    set_shadow(shadow);
    return *this;
}

Label& Label::with_string(const std::string& string)
{
    set_string(string);
    return *this;
}

Label& Label::with_visibility(bool visible)
{
    set_visibility(visible);
    return *this;
}

void Label::update_texture()
{
    texture = renderer.render_text(string, color);
    texture_shadow = renderer.render_text(string, { 0, 0, 0 });
    set_position(position);
}
