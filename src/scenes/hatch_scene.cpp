//
// AUGMENTS
//
// Copyright 2022 Christopher Borsellino
// All rights reserved.
//

#include "hatch_scene.h"

HatchScene::HatchScene(Game& game, const Creature& creature)
    : Scene(game), creature(creature)
{
    RarityID rarity = game.cache.get_species(creature.species_id).rarity;

    widgets.add<Image>("animation")
        .with_anim_frame_count(26)
        .with_anim_frame_size({ 102, 102 })
        .with_position({ 230, 114 })
        .with_texture(game.renderer.get_textures().get_egg_icon(rarity));

    widgets.add<Image>("image")
        .with_position({ 204, 75 + 4 + 9 })
        .with_texture(game.renderer.get_textures().get_species(creature.species_id))
        .with_visibility(false);

    widgets.add<Label>("label")
        .with_alignment(Label::center)
        .with_color({ 243, 239, 225 })
        .with_position({ 96 + 288 / 2, 184 })
        .with_shadow(true)
        .with_string("The egg is hatching...");

    widgets.add<Button>("button")
        .with_action(std::bind(&HatchScene::start, this))
        .with_bounds({ 218, 200, 44, 18 })
        .with_string("ok");
}

void HatchScene::handle_event(const SDL_Event& e)
{
    widgets.handle_event(e);
}

void HatchScene::update()
{
    if (widgets.find<Image>("animation").is_anim_finished())
        end();

    widgets.update();
}

void HatchScene::draw() const
{
    game.renderer.fade();

    game.renderer.draw_border({ 100, 58, 280, 166 }, game.renderer.get_textures().get_general("frame"), { 59, 59, 53 });

    widgets.draw();
}

void HatchScene::start()
{
    widgets.find<Label>("label").set_visibility(false);

    RarityID rarity = game.cache.get_species(creature.species_id).rarity;

    auto& animation = widgets.find<Image>("animation");
    animation.set_anim_type(Image::anim_type_frame);
    animation.set_texture(game.renderer.get_textures().get_hatch_animation(rarity));
    animation.set_position({ 189, 73 });

    widgets.find<Button>("button").set_visibility(false);
}

void HatchScene::end()
{
    widgets.find<Image>("animation").set_visibility(false);
    widgets.find<Image>("image").set_visibility(true);

    auto& button = widgets.find<Button>("button");
    button.set_action(std::bind(&Game::pop_scene, &game, 1));
    button.set_string("back");
    button.set_visibility(true);

    auto& label = widgets.find<Label>("label");
    label.set_string(creature.name + " hatched from the egg!");
    label.set_visibility(true);
}
