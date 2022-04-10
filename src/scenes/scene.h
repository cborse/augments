#pragma once

#include "game.h"
#include "widgets/widget_container.h"

class Scene {
public:
    virtual ~Scene() = default;

    virtual void pause() = 0;
    virtual void unpause() = 0;
    virtual void handle_event(const SDL_Event& e) = 0;
    virtual void update() = 0;
    virtual void draw() const = 0;

protected:
    explicit Scene(Game& game) : game(game), widgets(game.renderer, game.textures) {}

    Game& game;
    WidgetContainer widgets;
};
