//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#include <SDL_image.h>
#include "renderer.h"
#include "error.h"

Renderer::Renderer()
{
    // Window
    window = SDL_CreateWindow("AUGMENTS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              size.x * 3, size.y * 3, SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_RESIZABLE);
    if (!window) {
        std::string msg(SDL_GetError());
        throw Error("Failed to create window : " + msg + ".");
    }

    // Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::string msg(SDL_GetError());
        throw Error("Failed to create renderer: " + msg + ".");
    }

    SDL_RenderSetLogicalSize(renderer, size.x, size.y);

    // Font
    font = TTF_OpenFont("assets/font.ttf", 8);
    if (!font) {
        std::string msg(TTF_GetError());
        throw Error("Failed to load font: " + msg + ".");
    }

    // Load all textures
    textures.load(*this);
}

Renderer::~Renderer()
{
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void Renderer::present() const
{
    SDL_RenderPresent(renderer);
}

void Renderer::clear(const SDL_Color& color) const
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(renderer);
}

void Renderer::toggle_fullscreen() const
{
    Uint32 flags = SDL_GetWindowFlags(window);
    SDL_SetWindowFullscreen(window, flags ^ SDL_WINDOW_FULLSCREEN_DESKTOP);
}

void Renderer::fade(uint8_t alpha) const
{
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    fill_rect({ 0, 0, size.x, size.y }, { 0, 0, 0, alpha });
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
}

void Renderer::draw_rect(const SDL_Rect& rect, const SDL_Color& color) const
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawRect(renderer, &rect);
}

void Renderer::fill_rect(const SDL_Rect& rect, const SDL_Color& color) const
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
}

void Renderer::draw(const Texture& texture, const SDL_Point& position) const
{
    SDL_Rect dst = { position.x, position.y, texture.size.x, texture.size.y };
    SDL_RenderCopy(renderer, texture.texture, nullptr, &dst);
}

void Renderer::draw_angle(const Texture& texture, const SDL_Point& position, double angle) const
{
    SDL_Rect dst = { position.x, position.y, texture.size.x, texture.size.y };
    SDL_Point center = { texture.size.x / 2, texture.size.y };
    SDL_RenderCopyEx(renderer, texture.texture, nullptr, &dst, angle, &center, SDL_FLIP_NONE);
}

void Renderer::draw_sub(const Texture& texture, const SDL_Point& position, const SDL_Rect& sub) const
{
    SDL_Rect dst = { position.x, position.y, sub.w, sub.h };
    SDL_RenderCopy(renderer, texture.texture, &sub, &dst);
}

void Renderer::draw_border(const SDL_Rect& bounds, const Texture& texture, const SDL_Color& fill_color) const
{
    // Corners
    draw_sub(texture, { bounds.x, bounds.y }, { 0, 0, 5, 5 });
    draw_sub(texture, { bounds.x + bounds.w - 5, bounds.y }, { 6, 0, 5, 5 });
    draw_sub(texture, { bounds.x, bounds.y + bounds.h - 5 }, { 0, 6, 5, 5 });
    draw_sub(texture, { bounds.x + bounds.w - 5, bounds.y + bounds.h - 5 }, { 6, 6, 5, 5 });

    // Top and bottom
    for (int i = 0; i < bounds.w - 10; i++) {
        draw_sub(texture, { bounds.x + 5 + i, bounds.y }, { 5, 0, 1, 5 });
        draw_sub(texture, { bounds.x + 5 + i, bounds.y + bounds.h - 5 }, { 5, 6, 1, 5 });
    }

    // Sides
    for (int i = 0; i < bounds.h - 10; i++) {
        draw_sub(texture, { bounds.x, bounds.y + 5 + i }, { 0, 5, 5, 1 });
        draw_sub(texture, { bounds.x + bounds.w - 5, bounds.y + 5 + i }, { 6, 5, 5, 1 });
    }

    // Fill
    fill_rect({ bounds.x + 5, bounds.y + 5, bounds.w - 10, bounds.h - 10 }, fill_color);
}


Texture Renderer::render_text(const std::string& string, const SDL_Color& color) const
{
    SDL_Surface* surface = TTF_RenderUTF8_Solid(font, string.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

Texture Renderer::load_texture(const std::string& filename) const
{
    SDL_Texture* texture = IMG_LoadTexture(renderer, filename.c_str());
    if (!texture)
        throw Error("Failed to load texture: " + filename);
    return texture;
}

const TextureContainer& Renderer::get_textures() const
{
    return textures;
}
