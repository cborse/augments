#pragma once

#include "graphics/texture_container.h"

class Widget {
public:
    virtual ~Widget() = default;

    virtual bool handle_event(const SDL_Event& e) = 0;
    virtual void update() = 0;
    virtual void draw() const = 0;

protected:
    Widget(const Renderer& renderer, const TextureContainer& textures) : renderer(renderer), textures(textures) {}

    const Renderer& renderer;
    const TextureContainer& textures;
};
