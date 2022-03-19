//
// AUGMENTS
//
// Copyright 2022 Christopher Borsellino
// All rights reserved.
//

#include "game.h"
#include "scenes/login_scene.h"

Game::Game()
{
    SDL_ShowCursor(SDL_DISABLE);
}

Game::~Game()
{
}

void Game::loop()
{
    push_scene(std::make_unique<LoginScene>(*this));

    uint64_t last_count = 0;

    for (;;) {
        const uint64_t this_count = SDL_GetPerformanceCounter();
        const float delta = (this_count - last_count) / (float)SDL_GetPerformanceFrequency();
        if (delta < 1.f / Renderer::framerate)
            continue;

        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                return;

            else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_F11)
                renderer.toggle_fullscreen();

            else if (e.type == SDL_MOUSEMOTION)
                renderer.update_mouse(e);

            else if (!scenes.empty())
                scenes.back()->handle_event(e);
        }

        SteamAPI_RunCallbacks();
        api.update();

        if (!scenes.empty())
            scenes.back()->update();

        renderer.clear();
        for (const auto& scene : scenes)
            scene->draw();
        renderer.draw(renderer.get_textures().get_general("cursor"), renderer.get_mouse());
        renderer.present();

        last_count = this_count;
    }
}

void Game::set_scene(std::unique_ptr<Scene> scene)
{
    while (!scenes.empty())
        scenes.pop_back();
    scenes.push_back(std::move(scene));
}

void Game::push_scene(std::unique_ptr<Scene> scene)
{
    scenes.push_back(std::move(scene));
}

void Game::pop_scene(int count)
{
    for (int i = 0; i < count; i++)
        scenes.pop_back();
    if (!scenes.empty())
        scenes.back()->resume();
}
