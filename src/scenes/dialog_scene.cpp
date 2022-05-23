#include "dialog_scene.h"

DialogScene::DialogScene(Game& game)
    : Scene(game)
{
}

void DialogScene::handle_event(const SDL_Event& e)
{
    widgets.handle_event(e);
}

void DialogScene::update()
{
    widgets.update();
}

void DialogScene::draw() const
{
    game.renderer.fade();
    game.renderer.draw_border({ 140, 85, 200, num_lines * 14 + 14 + 24 }, "window", { 23, 23, 20 });

    widgets.draw();
}

void DialogScene::add_line(const std::string& line)
{
    widgets.add<Label>()
        .with_color({ 243, 239, 225 })
        .with_position({ 152, 97 + num_lines * 14 })
        .with_string(line);

    num_lines++;
}

void DialogScene::add_choice(const std::string& string, std::function<void()> action)
{
    widgets.add<Button>()
        .with_action(action)
        .with_bounds({ 152 + 56 * num_choices, 97 + num_lines * 14, 52, 18 })
        .with_string(string);

    num_choices++;
}
