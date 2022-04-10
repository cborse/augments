#pragma once

#include "cache/cache.h"
#include "graphics/texture_container.h"
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
    TextureContainer textures;

private:
    std::vector<std::unique_ptr<Scene>> scenes;
};
