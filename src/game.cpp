#include <steam/steam_api.h>
#include "game.h"
#include "scenes/login_scene.h"

Game::Game()
    : textures(renderer)
{
    SDL_ShowCursor(SDL_DISABLE);
}

Game::~Game()
{
}

void Game::loop()
{
    SDL_Point mouse = {};
    uint64_t last_count = 0;

    push_scene(std::make_unique<LoginScene>(*this));

    for (;;) {
        const uint64_t this_count = SDL_GetPerformanceCounter();
        const float delta = (this_count - last_count) / (float)SDL_GetPerformanceFrequency();
        if (delta < 1.f / Renderer::fps)
            continue;

        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
            case SDL_QUIT:
                return;

            case SDL_KEYUP:
                if (e.key.keysym.sym == SDLK_F11)
                    renderer.toggle_fullscreen();
                break;

            case SDL_MOUSEMOTION:
                mouse = { e.motion.x, e.motion.y };

            default:
                if (!scenes.empty())
                    scenes.back()->handle_event(e);
                break;
            }
        }

        SteamAPI_RunCallbacks();
        http.update();

        if (!scenes.empty())
            scenes.back()->update();

        renderer.clear();
        for (const auto& scene : scenes)
            scene->draw();
        renderer.draw(textures.get_general("cursor"), mouse);
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
    if (!scenes.empty())
        scenes.back()->pause();
    scenes.push_back(std::move(scene));
}

void Game::pop_scene(int count)
{
    for (int i = 0; i < count; i++)
        scenes.pop_back();
    if (!scenes.empty())
        scenes.back()->unpause();
}
