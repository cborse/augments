#include "learn_scene.h"

LearnScene::LearnScene(Game& game, const Augment& augment, Creature& creature)
    : Scene(game), info(game.renderer, game.textures), augment(augment), creature(creature)
{
    // Back button
    widgets.add<Button>()
        .with_action(std::bind(&Game::pop_scene, &game, 1))
        .with_bounds({ 8, 3, 44, 18 })
        .with_string("BACK");

    bool is_action = std::holds_alternative<Action>(augment);

    // Title
    widgets.add<Label>()
        .with_color({ 23, 23, 20 })
        .with_position({ 60, 8 })
        .with_shadow(false)
        .with_string(std::string("REPLACE WHICH ") + (is_action ? "ACTION?" : "SKILL?"));

    // Headings
    widgets.add<Label>()
        .with_color({ 23, 23, 20 })
        .with_position({ 42, 41 })
        .with_string("CURRENT")
        .with_shadow(false);

    widgets.add<Label>()
        .with_color({ 23, 23, 20 })
        .with_position({ 42, 41 + 96 })
        .with_string("NEW")
        .with_shadow(false);

    // Augments
    for (int i = 0; i < 3; i++) {
        widgets.add<Cell>("cell-list" + std::to_string(i))
            .with_action(std::bind(&LearnScene::click_list, this, i))
            .with_bounds({ 42, 55 + i * 24, 135, 18 })
            .with_image_offset({ -24, -1 });
    }

    widgets.add<Cell>("cell-list3")
        .with_action(std::bind(&LearnScene::click_list, this, 3))
        .with_bounds({ 42, 55 + 4 * 24, 135, 18 })
        .with_image_offset({ -24, -1 });

    // Control
    widgets.add<Button>("button-control")
        .with_action(std::bind(&LearnScene::replace, this))
        .with_bounds({ 394, 36, 68, 18 })
        .with_string("REPLACE");

    refresh_widgets();
}

void LearnScene::handle_event(const SDL_Event& e)
{
    widgets.handle_event(e);
}

void LearnScene::update()
{
    widgets.update();
}

void LearnScene::draw() const
{
    game.renderer.clear({ 243, 239, 225 });

    game.renderer.draw_border({ 8, 23, 464, 239 }, game.textures.get_general("window"), { 23, 23, 20 });
    game.renderer.draw_border({ 12, 27, 172, 230 }, game.textures.get_general("frame"), { 59, 59, 53 });
    info.draw();

    widgets.draw();
}

void LearnScene::refresh_widgets()
{
    refresh_list_widgets();
    refresh_control_widgets();

    if (index >= 0 && index < 3) {
        if (std::holds_alternative<Action>(augment))
            info.set_augment(game.cache.get_action(creature.actions[index]));
        else if (std::holds_alternative<Skill>(augment))
            info.set_augment(game.cache.get_skill(creature.skills[index]));
    }
    else {
        if (std::holds_alternative<Action>(augment))
            info.set_augment(std::get<Action>(augment));
        else if (std::holds_alternative<Skill>(augment))
            info.set_augment(std::get<Skill>(augment));
    }
}

void LearnScene::refresh_list_widgets()
{
    for (int i = 0; i < 3; i++) {
        auto& cell = widgets.find<Cell>("cell-list" + std::to_string(i));
        cell.set_active(i == index);

        if (std::holds_alternative<Action>(augment)) {
            const Action& action = game.cache.get_action(creature.actions[i]);
            if (action.id != 0) {
                cell.get_image().set_texture(game.textures.get_action_augment(action.type));
                cell.get_label().set_string(action.name);
            }
            else {
                cell.get_image().set_visibility(false);
                cell.get_label().set_string("-");
            }
        }
        else if (std::holds_alternative<Skill>(augment)) {
            const Skill& skill = game.cache.get_skill(creature.skills[i]);
            if (skill.id != 0) {
                cell.get_image().set_texture(game.textures.get_skill_augment());
                cell.get_label().set_string(skill.name);
            }
            else {
                cell.get_image().set_visibility(false);
                cell.get_label().set_string("-");
            }
        }
    }

    auto& cell_new = widgets.find<Cell>("cell-list3");
    cell_new.set_active(index == 3);

    if (std::holds_alternative<Action>(augment)) {
        const Action& action = std::get<Action>(augment);
        cell_new.get_image().set_texture(game.textures.get_action_augment(action.type));
        cell_new.get_label().set_string(action.name);
    }
    else if (std::holds_alternative<Skill>(augment)) {
        const Skill& skill = std::get<Skill>(augment);
        cell_new.get_image().set_texture(game.textures.get_skill_augment());
        cell_new.get_label().set_string(skill.name);
    }
}

void LearnScene::refresh_control_widgets()
{
    auto& control = widgets.find<Button>("button-control");
    control.set_visibility(index >= 0 && index < 3);
}

void LearnScene::click_list(int i)
{
    if (index != i) {
        index = i;
        refresh_widgets();
    }
}

void LearnScene::replace()
{
    if (std::holds_alternative<Action>(augment)) {
        const Action& action = std::get<Action>(augment);

        // Client
        creature.actions[index] = action.id;
        game.cache.user_actions[action.id]--;

        // Server
        const nlohmann::json json = {
            { "creature_id", creature.id },
            { "slot", index },
            { "action_id", action.id }
        };

        game.http.push_request()
            .with_body(json.dump())
            .with_uri("learn_action");
    }
    else if (std::holds_alternative<Skill>(augment)) {
        const Skill& skill = std::get<Skill>(augment);

        // Client
        creature.skills[index] = skill.id;
        game.cache.user_skills[skill.id]--;

        // Server
        const nlohmann::json json = {
            { "creature_id", creature.id },
            { "slot", index },
            { "skill_id", skill.id }
        };

        game.http.push_request()
            .with_body(json.dump())
            .with_uri("learn_skill");
    }

    game.pop_scene(2);
}
