//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#include "team_scene.h"
#include "hatch_scene.h"

TeamScene::TeamScene(Game& game)
    : Scene(game)
{
    // Back/cancel button
    widgets.add<Button>()
        .with_action(std::bind(&Game::pop_scene, &game))
        .with_bounds({ 8, 3, 44, 18 })
        .with_string("back");

    // Title
    widgets.add<Label>()
        .with_color({ 23, 23, 20 })
        .with_position({ 60, 8 })
        .with_shadow(false)
        .with_string("STAFFS");

    // List
    widgets.add<Button>("button-staff_left")
        .with_action(std::bind(&TeamScene::click_staff_left, this))
        .with_bounds({ 18, 36, 20, 18 })
        .with_string("<");

    widgets.add<Button>("button-staff_right")
        .with_action(std::bind(&TeamScene::click_staff_right, this))
        .with_bounds({ 126, 36, 20, 18 })
        .with_string(">");

    widgets.add<Label>("label-staff_page")
        .with_alignment(Label::center)
        .with_color({ 243, 239, 225 })
        .with_position({ 12 + 140 / 2, 41 });

    for (int i = 0; i < 8; i++) {
        widgets.add<Cell>("cell-list" + std::to_string(i))
            .with_action(std::bind(&TeamScene::click_list, this, i))
            .with_bounds({ 42, 63 + i * 24, 103, 18 })
            .with_image_offset({ -24, -1 });
    }

    // Grid
    for (int i = 0; i < 20; i++) {
        widgets.add<Cell>("cell-grid" + std::to_string(i))
            .with_action(std::bind(&TeamScene::click_grid, this, i))
            .with_bounds({ 162 + i % 4 * 42, 65 + i / 4 * 38, 36, 32 })
            .with_image_offset({ 8, 6 });

        widgets.add<Image>("image-assigned" + std::to_string(i))
            .with_position({ 189 + i % 4 * 42, 88 + i / 4 * 38 })
            .with_texture(game.renderer.get_textures().get_general("assigned"));
    }

    // Pages
    widgets.add<Button>("button-storage_left")
        .with_action(std::bind(&TeamScene::click_storage_left, this))
        .with_bounds({ 160, 36, 20, 18 })
        .with_string("<");

    widgets.add<Button>("button-storage_right")
        .with_action(std::bind(&TeamScene::click_storage_right, this))
        .with_bounds({ 306, 36, 20, 18 })
        .with_string(">");

    widgets.add<Label>("label-storage_page")
        .with_alignment(Label::center)
        .with_color({ 243, 239, 225 })
        .with_position({ 154 + 178 / 2, 41 });

    // Summary
    widgets.add<Label>("label-summary_name")
        .with_alignment(Label::center)
        .with_color({ 243, 239, 225 })
        .with_position({ 334 + 134 / 2, 41 });

    widgets.add<Image>("image-summary")
        .with_position({ 365, 60 });

    widgets.add<Image>("image-summary_level")
        .with_position({ 344, 138 })
        .with_texture(game.renderer.get_textures().get_general("level"));

    widgets.add<Label>("label-summary_level")
        .with_color({ 243, 239, 225 })
        .with_position({ 363, 141 });

    widgets.add<Image>("image-summary_xp")
        .with_position({ 392, 138 })
        .with_texture(game.renderer.get_textures().get_general("xp"));

    widgets.add<Label>("label-summary_xp")
        .with_color({ 243, 239, 225 })
        .with_position({ 411, 141 });

    widgets.add<Label>("label-summary_next")
        .with_color({ 243, 239, 225 })
        .with_position({ 344, 157 })
        .with_string("next");

    widgets.add<ProgressBar>("pbar-summary")
        .with_bounds({ 380, 157, 78, 8 });

    // Controls
    for (int i = 0; i < 4; i++) {
        widgets.add<Button>("button-control" + std::to_string(i))
            .with_bounds({ 354, 171 + i * 21, 94, 18 });
    }

    refresh_data();
    refresh_widgets();
}

void TeamScene::handle_event(const SDL_Event& e)
{
    widgets.handle_event(e);
}

void TeamScene::update()
{
    widgets.update();
}

void TeamScene::draw() const
{
    game.renderer.clear({ 243, 239, 225 });

    game.renderer.draw_border({ 8, 23, 464, 239 }, game.renderer.get_textures().get_general("window"), { 23, 23, 20 });
    game.renderer.draw_border({ 12, 27, 140, 230 }, game.renderer.get_textures().get_general("frame"), { 59, 59, 53 });
    game.renderer.draw_border({ 154, 27, 178, 230 }, game.renderer.get_textures().get_general("frame"), { 59, 59, 53 });
    game.renderer.draw_border({ 334, 27, 134, 230 }, game.renderer.get_textures().get_general("frame"), { 59, 59, 53 });

    widgets.draw();
}

void TeamScene::refresh_data()
{
    eggs.clear();
    storage.clear();
    staff_creatures.clear();
    staff_creatures.resize(game.cache.staffs.size());

    for (auto& creature : game.cache.creatures) {
        if (creature.is_egg) {
            eggs.push_back(&creature);
        }
        else {
            storage.push_back(&creature);
            if (creature.staff_slot != -1)
                staff_creatures.at(creature.staff_slot).push_back(&creature);
        }
    }
}

void TeamScene::refresh_widgets()
{
    refresh_list_widgets();
    refresh_grid_widgets();
    refresh_summary_widgets();
    refresh_staff_widgets();
    refresh_page_widgets();
    refresh_control_widgets();
    animate_pair();
}

void TeamScene::refresh_list_widgets()
{
    int size = (int)staff_creatures.at(staff).size();
    for (int i = 0; i < 8; i++) {
        auto& cell = widgets.find<Cell>("cell-list" + std::to_string(i));
        cell.set_active(i == index);
        cell.set_visibility(i < size);

        auto& cell_image = cell.get_image();
        if (i == index)
            cell_image.set_anim_type(Image::anim_type_bounce);
        else
            cell_image.set_anim_type(Image::anim_type_none);

        if (i < size) {
            const Creature* creature = staff_creatures.at(staff).at(i);
            cell.set_string(creature->name);
            cell.set_texture(game.renderer.get_textures().get_species_icon(creature->species_id));
        }
    }
}

void TeamScene::refresh_grid_widgets()
{
    int size = page == -1 ? (int)eggs.size() : (int)storage.size() - page * 20;
    for (int i = 0; i < 20; i++) {
        auto& cell = widgets.find<Cell>("cell-grid" + std::to_string(i));
        cell.set_active(i == index - 8);
        cell.set_visibility(i < size);

        auto& cell_image = cell.get_image();
        if (page != -1 && i == index - 8)
            cell_image.set_anim_type(Image::anim_type_bounce);
        else
            cell_image.set_anim_type(Image::anim_type_none);

        auto& assigned = widgets.find<Image>("image-assigned" + std::to_string(i));
        assigned.set_visibility(false);

        if (i < size) {
            if (page == -1) {
                const Creature* creature = eggs.at(i);
                const Species& species = game.cache.get_species(creature->species_id);
                cell.set_texture(game.renderer.get_textures().get_egg_icon(species.rarity));

                // Special animation for egg ready to hatch
                if (creature->wins >= (uint32_t)species.get_needed_egg_wins())
                    cell_image.set_anim_type(Image::anim_type_shake);
            }
            else {
                const Creature* creature = storage.at(i + page * 20);
                assigned.set_visibility(creature->staff_slot != -1);
                cell.set_texture(game.renderer.get_textures().get_species_icon(creature->species_id));
            }
        }
    }
}

void TeamScene::refresh_summary_widgets()
{
    auto& image_creature = widgets.find<Image>("image-summary");
    auto& label_name = widgets.find<Label>("label-summary_name");
    auto& image_level = widgets.find<Image>("image-summary_level");
    auto& label_level = widgets.find<Label>("label-summary_level");
    auto& image_xp = widgets.find<Image>("image-summary_xp");
    auto& label_xp = widgets.find<Label>("label-summary_xp");
    auto& label_next = widgets.find<Label>("label-summary_next");
    auto& pbar = widgets.find<ProgressBar>("pbar-summary");

    const Creature* creature = get_selected_creature();

    image_creature.set_visibility(creature);
    label_name.set_visibility(creature);
    image_level.set_visibility(creature && page != -1);
    label_level.set_visibility(creature && page != -1);
    image_xp.set_visibility(creature && page != -1);
    label_xp.set_visibility(creature && page != -1);
    label_next.set_visibility(creature && page != -1);
    pbar.set_visibility(creature && page != -1);

    if (creature) {
        if (page == -1) {
            const Species& species = game.cache.get_species(creature->species_id);
            image_creature.set_texture(game.renderer.get_textures().get_egg(species.rarity));
            label_name.set_string("EGG");
        }
        else {
            image_creature.set_texture(game.renderer.get_textures().get_species(creature->species_id));
            label_name.set_string(creature->name);
            label_level.set_string(std::to_string(creature->get_level()));
            label_xp.set_string(std::to_string(creature->xp));
            pbar.set_value(creature->get_level_progress());
        }
    }
}

void TeamScene::refresh_staff_widgets()
{
    auto& label_left = widgets.find<Button>("button-staff_left");
    label_left.set_visibility(staff > 0);

    auto& label_right = widgets.find<Button>("button-staff_right");
    label_right.set_visibility(staff + 1 < (int)game.cache.staffs.size());

    auto& label_page = widgets.find<Label>("label-staff_page");
    label_page.set_string(game.cache.staffs.at(staff).name);
}

void TeamScene::refresh_page_widgets()
{
    auto& label_left = widgets.find<Button>("button-storage_left");
    label_left.set_visibility(page > -1);

    auto& label_right = widgets.find<Button>("button-storage_right");
    label_right.set_visibility(page + 1 < (int)game.cache.user.storage_pages && !storage.empty());

    auto& label_page = widgets.find<Label>("label-storage_page");
    label_page.set_string(page == -1 ? "Eggs" : "Storage " + std::to_string(page + 1));
}

void TeamScene::refresh_control_widgets()
{
    auto& control0 = widgets.find<Button>("button-control0");
    auto& control1 = widgets.find<Button>("button-control1");
    auto& control2 = widgets.find<Button>("button-control2");
    auto& control3 = widgets.find<Button>("button-control3");

    control0.set_visibility(false);
    control1.set_visibility(false);
    control2.set_visibility(false);
    control3.set_visibility(false);

    const Creature* creature = get_selected_creature();
    if (!creature)
        return;

    // Creature
    if (!creature->is_egg) {
        control0.set_visibility(true);
        control1.set_visibility(true);
        control2.set_visibility(true);
        control3.set_visibility(true);

        if (creature->staff_slot == -1) {
            control0.set_string("assign");
            control0.set_action(std::bind(&TeamScene::assign, this));
        }
        else {
            control0.set_string("unassign");
            control0.set_action(std::bind(&TeamScene::unassign, this));
        }

        control1.set_string("stats");
        control2.set_string("rename");
        control3.set_string("release");
    }
    // Egg
    else {
        const Species& species = game.cache.get_species(creature->species_id);
        if (creature->wins >= (uint32_t)species.get_needed_egg_wins()) {
            control3.set_visibility(true);
            control3.set_string("hatch");
            control3.set_action(std::bind(&TeamScene::hatch, this));
        }
    }
}

void TeamScene::animate_pair()
{
    const Creature* creature = get_selected_creature();
    if (!creature || creature->is_egg || page == -1 /*|| augment*/)
        return;

    if (index < 8) {
        for (int i = 0; i < 20 && i < storage.size() - page * 20; i++) {
            if (creature->id == storage.at(i + page * 20)->id) {
                auto& cell = widgets.find<Cell>("cell-grid" + std::to_string(i));
                cell.get_image().set_anim_type(Image::anim_type_bounce);
            }
        }
    }
    else {
        for (int i = 0; i < staff_creatures.at(staff).size(); i++) {
            if (creature->id == staff_creatures.at(staff).at(i)->id) {
                auto& cell = widgets.find<Cell>("cell-list" + std::to_string(i));
                cell.get_image().set_anim_type(Image::anim_type_bounce);
            }
        }
    }
}

void TeamScene::click_staff_left()
{
    staff--;
    refresh_widgets();
}

void TeamScene::click_staff_right()
{
    staff++;
    refresh_widgets();
}

void TeamScene::click_storage_left()
{
    page--;
    refresh_widgets();
}

void TeamScene::click_storage_right()
{
    page++;
    refresh_widgets();
}

void TeamScene::click_list(int i)
{
    if (index != i) {
        index = i;
        refresh_widgets();
    }
}

void TeamScene::click_grid(int i)
{
    if (index != i + 8) {
        index = i + 8;
        refresh_widgets();
    }
}

Creature* TeamScene::get_selected_creature() const
{
    if (index < 8) {
        if (index < staff_creatures.at(staff).size())
            return staff_creatures.at(staff).at(index);
    }
    else if (page == -1) {
        if (index - 8 < eggs.size())
            return eggs.at(index - 8);
    }
    else {
        if (index - 8 < storage.size() - page * 20)
            return storage.at(index - 8 + page * 20);
    }

    return nullptr;
}

void TeamScene::assign()
{
    Creature* creature = get_selected_creature();

    // Make sure there's room on the staff
    if (staff_creatures.at(staff).size() >= 8) {
        // error
        return;
    }

    // Client
    creature->staff_slot = staff;

    // Server
    const nlohmann::json json = { { "creature_id", creature->id }, { "staff_slot", staff } };
    game.api.push_request()
        .with_header_id(game.cache.user.id)
        .with_header_token(game.cache.user.token)
        .with_body(json.dump())
        .with_uri("assign");

    refresh_data();
    refresh_widgets();
}

void TeamScene::unassign()
{
    Creature* creature = get_selected_creature();

    // Client
    creature->staff_slot = -1;

    // Server
    const nlohmann::json json = { { "creature_id", creature->id } };
    game.api.push_request()
        .with_header_id(game.cache.user.id)
        .with_header_token(game.cache.user.token)
        .with_body(json.dump())
        .with_uri("unassign");

    refresh_data();
    refresh_widgets();
}

void TeamScene::hatch()
{
    Creature* creature = get_selected_creature();

    // Make sure there's room in storage
    if (storage.size() + 1 >= game.cache.user.storage_pages * 20) {
        // show error
        return;
    }

    // Client
    creature->is_egg = false;
    creature->wins = 0;

    // Server
    const nlohmann::json json = { { "creature_id", creature->id } };
    game.api.push_request()
        .with_header_id(game.cache.user.id)
        .with_header_token(game.cache.user.token)
        .with_body(json.dump())
        .with_uri("hatch_egg");

    refresh_data();
    refresh_widgets();

    game.push_scene(std::make_unique<HatchScene>(game, *creature));
}
