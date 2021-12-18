//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include "cache/cache.h"
#include "graphics/renderer.h"
#include "net/http_container.h"

class Scene;

class Game {
public:
    Game();
    ~Game();

    void loop();
    void set_scene(std::unique_ptr<Scene> scene);
    void push_scene(std::unique_ptr<Scene> scene);
    void pop_scene(int count = 1);

    Cache cache;
    HttpContainer api;
    Renderer renderer;

private:
    std::vector<std::unique_ptr<Scene>> scenes;
};
