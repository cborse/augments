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
    Renderer renderer;
    HttpContainer http;

private:
    std::vector<std::unique_ptr<Scene>> scenes;
};
