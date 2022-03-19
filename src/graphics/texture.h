//
// AUGMENTS
//
// Copyright 2022 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include <SDL.h>

class Texture {
public:
    Texture() = default;
    Texture(SDL_Texture* texture);
    Texture(const Texture&) = delete;
    Texture(Texture&& other) noexcept;
    ~Texture();

    Texture& operator=(const Texture&) = delete;
    Texture& operator=(Texture&& other) noexcept;

    const SDL_Point& get_size() const;
    void set_alpha(uint8_t alpha) const;

private:
    SDL_Point size = {};
    SDL_Texture* texture = nullptr;

    friend class Renderer;
};
