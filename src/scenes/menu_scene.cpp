//
// AUGMENTS
//
// Copyright 2022 Christopher Borsellino
// All rights reserved.
//

#include <steam/steam_api.h>
#include "augments_scene.h"
#include "menu_scene.h"
#include "team_scene.h"

MenuScene::MenuScene(Game& game)
    : Scene(game)
{
    widgets.add<Label>()
        .with_color({ 255, 0, 0 })
        .with_position({ 20, 20 })
        .with_shadow(false)
        .with_string(std::string("name: ") + SteamFriends()->GetPersonaName());

    widgets.add<Button>()
        .with_bounds({ 180, 100, 100, 18 })
        .with_string("battle");

    widgets.add<Button>()
        .with_action([&]() { game.push_scene(std::make_unique<TeamScene>(game)); })
        .with_bounds({ 180, 122, 100, 18 })
        .with_string("staffs");

    widgets.add<Button>()
        .with_action([&]() { game.push_scene(std::make_unique<AugmentsScene>(game)); })
        .with_bounds({ 180, 144, 100, 18 })
        .with_string("augments");

    widgets.add<Button>()
        .with_bounds({ 180, 166, 100, 18 })
        .with_string("market");

    widgets.add<Button>()
        .with_action([&] { SDL_Event e; e.type = SDL_QUIT; SDL_PushEvent(&e); })
        .with_bounds({ 180, 188, 100, 18 })
        .with_string("quit");
}

void MenuScene::handle_event(const SDL_Event& e)
{
    widgets.handle_event(e);
}

void MenuScene::update()
{
    widgets.update();
}

void MenuScene::draw() const
{
    game.renderer.clear({ 243, 239, 225 });
    widgets.draw();
}
