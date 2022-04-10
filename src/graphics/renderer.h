#pragma once

#include <string>
#include <SDL_ttf.h>
#include "texture.h"

class Renderer {
public:
    Renderer();
    ~Renderer();

    void present() const;
    void clear(const SDL_Color& color = {}) const;
    void toggle_fullscreen() const;
    void fade() const;

    void draw_rect(const SDL_Rect& rect, const SDL_Color& color) const;
    void fill_rect(const SDL_Rect& rect, const SDL_Color& color) const;

    void draw(const Texture& texture, const SDL_Point& position) const;
    void draw_angle(const Texture& texture, const SDL_Point& position, double angle) const;
    void draw_sub(const Texture& texture, const SDL_Point& position, const SDL_Rect& sub) const;
    void draw_border(const SDL_Rect& bounds, const Texture& texture, const SDL_Color& fill_color) const;

    Texture render_text(const std::string& string, const SDL_Color& color) const;
    Texture load_texture(const std::string& filename) const;

    static constexpr SDL_Point size = { 480, 270 };
    static constexpr unsigned int fps = 60;

private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    TTF_Font* font = nullptr;
};
