//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#include "augments_scene.h"
#include "team_scene.h"

AugmentsScene::AugmentsScene(Game& game)
    : Scene(game)
{
    // Back button
    widgets.add<Button>()
        .with_action(std::bind(&Game::pop_scene, &game))
        .with_bounds({ 8, 3, 44, 18 })
        .with_string("back");

    // Title
    widgets.add<Label>()
        .with_color({ 23, 23, 20 })
        .with_position({ 60, 8 })
        .with_shadow(false)
        .with_string("AUGMENTS");

    // Pages
    widgets.add<Button>("button-page_left")
        .with_action(std::bind(&AugmentsScene::click_page_left, this))
        .with_bounds({ 18, 36, 20, 18 })
        .with_string("<");

    widgets.add<Button>("button-page_right")
        .with_action(std::bind(&AugmentsScene::click_page_right, this))
        .with_bounds({ 157, 36, 20, 18 })
        .with_string(">");

    widgets.add<Label>("label-page")
        .with_alignment(Label::center)
        .with_color({ 243, 239, 225 })
        .with_position({ 12 + 172 / 2, 41 })
        .with_shadow(true);

    // Augments
    for (int i = 0; i < 8; i++) {
        widgets.add<Cell>("cell-list" + std::to_string(i))
            .with_action(std::bind(&AugmentsScene::click_list, this, i))
            .with_bounds({ 42, 63 + i * 24, 135, 18 })
            .with_image_offset({ -24, -1 });

        widgets.add<Label>("label-list_qty" + std::to_string(i))
            .with_alignment(Label::right)
            .with_color({ 243, 239, 225 })
            .with_position({ 174, 69 + i * 24 });
    }

    // Info
    widgets.add<Label>("label-info_name")
        .with_color({ 243, 239, 225 })
        .with_position({ 224, 41 });

    widgets.add<Image>("image-info_icon")
        .with_position({ 196, 34 });

    widgets.add<Label>("label-info_desc0")
        .with_color({ 23, 23, 20 })
        .with_position({ 196, 69 })
        .with_string("DESCRIPTION")
        .with_shadow(false);

    for (int i = 1; i <= 3; i++) {
        widgets.add<Label>("label-info_desc" + std::to_string(i))
            .with_color({ 243, 239, 225 })
            .with_position({ 196, 69 + i * 14 });
    }

    const std::vector<std::string> detail_strings = {
        "POWER", "ENERGY", "SPEED",
        "ACCURACY", "STYLE", "CONTACT",
        "COVER", "DETECT", "MOVE"
    };

    for (int i = 0; i < 9; i++) {
        widgets.add<Label>("label-info_detail" + std::to_string(i))
            .with_alignment(Label::center)
            .with_color({ 23, 23, 20 })
            .with_position({ 196 + i % 3 * 90 + 82 / 2, 132 + i / 3 * 44 })
            .with_string(detail_strings.at(i))
            .with_shadow(false);

        widgets.add<Cell>("cell-info_detail" + std::to_string(i))
            .with_bounds({ 196 + i % 3 * 90, 143 + i / 3 * 44, 82, 18 })
            .with_label_alignment(Label::center);
    }

    // Controls
    for (int i = 0; i < 2; i++) {
        widgets.add<Button>("button-control" + std::to_string(i))
            .with_bounds({ 354 + i * 56, 36, 52, 18 });
    }

    refresh_data();
    refresh_widgets();
}

void AugmentsScene::handle_event(const SDL_Event& e)
{
    widgets.handle_event(e);
}

void AugmentsScene::update()
{
    widgets.update();
}

void AugmentsScene::draw() const
{
    game.renderer.clear({ 243, 239, 225 });

    game.renderer.draw_border({ 8, 23, 464, 239 }, game.renderer.get_textures().get_general("window"), { 23, 23, 20 });
    game.renderer.draw_border({ 12, 27, 172, 230 }, game.renderer.get_textures().get_general("frame"), { 59, 59, 53 });
    game.renderer.draw_border({ 186, 27, 282, 230 }, game.renderer.get_textures().get_general("frame"), { 59, 59, 53 });

    widgets.draw();
}

void AugmentsScene::refresh_data()
{
    augments.clear();
    for (const auto& action : game.cache.user_actions)
        augments.push_back(game.cache.get_action(action.action_id));
    for (const auto& skill : game.cache.user_skills)
        augments.push_back(game.cache.get_skill(skill.skill_id));

    auto lambda = [](auto const& x) {
        return std::visit([](auto const& e) { return e.name; }, x);
    };
    std::ranges::sort(augments, std::less(), lambda);
}

void AugmentsScene::refresh_widgets()
{
    refresh_list_widgets();
    refresh_info_widgets();
    refresh_page_widgets();
    refresh_control_widgets();
}

void AugmentsScene::refresh_list_widgets()
{
    int size = get_page_size();

    for (int i = 0; i < 8; i++) {
        auto& cell = widgets.find<Cell>("cell-list" + std::to_string(i));
        cell.set_active(i == index);
        cell.set_visibility(i < size);

        auto& label_qty = widgets.find<Label>("label-list_qty" + std::to_string(i));
        label_qty.set_visibility(i < size);

        if (i < size) {
            const Augment& augment = augments.at(i + page * 8);

            if (std::holds_alternative<Action>(augment)) {
                const Action& action = std::get<Action>(augment);

                cell.get_image().set_texture(game.renderer.get_textures().get_augment(action.type));

                cell.get_label().set_string(action.name);

                std::string qty = std::to_string(game.cache.get_quantity(action));
                label_qty.set_string(qty.length() > 1 ? ("x" + qty) : "x " + qty);
            }
            else if (std::holds_alternative<Skill>(augment)) {
                const Skill& skill = std::get<Skill>(augment);

                cell.get_image().set_texture(game.renderer.get_textures().get_skill());

                cell.get_label().set_string(skill.name);

                std::string qty = std::to_string(game.cache.get_quantity(skill));
                label_qty.set_string(qty.length() > 1 ? ("x" + qty) : "x " + qty);
            }
        }
    }
}

void AugmentsScene::refresh_info_widgets()
{
    const Augment* augment = get_selected_augment();

    auto& name = widgets.find<Label>("label-info_name");
    name.set_visibility(augment);

    auto& icon = widgets.find<Image>("image-info_icon");
    icon.set_visibility(augment);

    auto& desc0 = widgets.find<Label>("label-info_desc0");
    desc0.set_visibility(augment);

    auto& desc1 = widgets.find<Label>("label-info_desc1");
    desc1.set_visibility(augment);

    auto& desc2 = widgets.find<Label>("label-info_desc2");
    desc2.set_visibility(augment);

    auto& desc3 = widgets.find<Label>("label-info_desc3");
    desc3.set_visibility(augment);

    for (int i = 0; i < 9; i++) {
        auto& detail_label = widgets.find<Label>("label-info_detail" + std::to_string(i));
        detail_label.set_visibility(augment && std::holds_alternative<Action>(*augment));

        auto& detail_cell = widgets.find<Cell>("cell-info_detail" + std::to_string(i));
        detail_cell.set_visibility(augment && std::holds_alternative<Action>(*augment));
    }

    if (augment) {
        if (std::holds_alternative<Action>(*augment)) {
            const Action& action = std::get<Action>(*augment);

            name.set_string(action.name);
            icon.set_texture(game.renderer.get_textures().get_augment(action.type));
            desc1.set_string(action.desc1);
            desc2.set_string(action.desc2);
            desc3.set_string(action.desc3);

            auto& power = widgets.find<Cell>("cell-info_detail0");
            power.set_string(action.power == 0 ? "-" : std::to_string(action.power));

            auto& energy = widgets.find<Cell>("cell-info_detail1");
            energy.set_string(action.energy == 0 ? "-" : std::to_string(action.energy));

            auto& speed = widgets.find<Cell>("cell-info_detail2");
            speed.set_string(action.speed == 0 ? "-" : std::to_string(action.speed));

            auto& accuracy = widgets.find<Cell>("cell-info_detail3");
            accuracy.set_string(action.accuracy == 0 ? "-" : std::to_string(action.accuracy));

            auto& style = widgets.find<Cell>("cell-info_detail4");
            style.set_string(Action::get_style_string(action.style));

            auto& contact = widgets.find<Cell>("cell-info_detail5");
            contact.set_string(action.contact ? "YES" : "NO");

            auto& cover = widgets.find<Cell>("cell-info_detail6");
            cover.set_string(Action::get_cover_string(action.cover));

            auto& detect = widgets.find<Cell>("cell-info_detail7");
            detect.set_string(action.detect ? "YES" : "NO");

            auto& move = widgets.find<Cell>("cell-info_detail8");
            move.set_string(Action::get_cover_string(action.move));
        }
        else if (std::holds_alternative<Skill>(*augment)) {
            const Skill& skill = std::get<Skill>(*augment);

            name.set_string(skill.name);
            icon.set_texture(game.renderer.get_textures().get_skill());
            desc1.set_string(skill.desc1);
            desc2.set_string(skill.desc2);
            desc3.set_string(skill.desc3);
        }
    }
}

void AugmentsScene::refresh_page_widgets()
{
    auto& label_storage_left = widgets.find<Button>("button-page_left");
    label_storage_left.set_visibility(page > 0);

    auto& label_storage_right = widgets.find<Button>("button-page_right");
    label_storage_right.set_visibility((page + 1) * 8 + 1 < (int)augments.size());

    auto& label_storage_page = widgets.find<Label>("label-page");
    label_storage_page.set_string("PAGE " + std::to_string(page + 1));
}

void AugmentsScene::refresh_control_widgets()
{
    int size = get_page_size();

    auto& control0 = widgets.find<Button>("button-control0");
    auto& control1 = widgets.find<Button>("button-control1");

    control0.set_visibility(index < size);
    control1.set_visibility(index < size);

    if (index < size) {
        control0.set_string("use");
        control0.set_action(std::bind(&AugmentsScene::use, this));

        control1.set_string("trash");
    }
}

void AugmentsScene::click_list(int i)
{
    if (index != i) {
        index = i;
        refresh_widgets();
    }
}

void AugmentsScene::click_page_left()
{
    page--;
    refresh_widgets();
}

void AugmentsScene::click_page_right()
{
    page++;
    refresh_widgets();
}

const Augment* AugmentsScene::get_selected_augment() const
{
    if (index < get_page_size())
        return &augments.at(index + page * 8);

    return nullptr;
}

int AugmentsScene::get_page_size() const
{
    return max(min((int)augments.size() - page * 8, 8), 0);
}

void AugmentsScene::use()
{
    game.push_scene(std::make_unique<TeamScene>(game, &augments.at(index + page * 8)));
}
