//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#include "augment_info.h"

AugmentInfo::AugmentInfo(const Renderer& renderer)
    : renderer(renderer), widgets(renderer)
{
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
}

void AugmentInfo::draw() const
{
    renderer.draw_border({ 186, 27, 282, 230 }, renderer.get_textures().get_general("frame"), { 59, 59, 53 });
    widgets.draw();
}

void AugmentInfo::set_augment(const Action& action)
{
    this->action = &action;
    skill = nullptr;
    refresh();
}

void AugmentInfo::set_augment(const Skill& skill)
{
    this->skill = &skill;
    action = nullptr;
    refresh();
}

void AugmentInfo::refresh()
{
    bool is_valid = (action && action->id != 0) || (skill && skill->id != 0);

    auto& name = widgets.find<Label>("label-info_name");
    name.set_visibility(is_valid);

    auto& icon = widgets.find<Image>("image-info_icon");
    icon.set_visibility(is_valid);

    auto& desc0 = widgets.find<Label>("label-info_desc0");
    desc0.set_visibility(is_valid);

    auto& desc1 = widgets.find<Label>("label-info_desc1");
    desc1.set_visibility(is_valid);

    auto& desc2 = widgets.find<Label>("label-info_desc2");
    desc2.set_visibility(is_valid);

    auto& desc3 = widgets.find<Label>("label-info_desc3");
    desc3.set_visibility(is_valid);

    for (int i = 0; i < 9; i++) {
        auto& detail_label = widgets.find<Label>("label-info_detail" + std::to_string(i));
        detail_label.set_visibility(action && action->id != 0);

        auto& detail_cell = widgets.find<Cell>("cell-info_detail" + std::to_string(i));
        detail_cell.set_visibility(action && action->id != 0);
    }

    if (action) {
        name.set_string(action->name);
        icon.set_texture(renderer.get_textures().get_augment(action->type));
        desc1.set_string(action->desc1);
        desc2.set_string(action->desc2);
        desc3.set_string(action->desc3);

        auto& power = widgets.find<Cell>("cell-info_detail0");
        power.set_string(action->power == 0 ? "-" : std::to_string(action->power));

        auto& energy = widgets.find<Cell>("cell-info_detail1");
        energy.set_string(action->energy == 0 ? "-" : std::to_string(action->energy));

        auto& speed = widgets.find<Cell>("cell-info_detail2");
        speed.set_string(action->speed == 0 ? "-" : std::to_string(action->speed));

        auto& accuracy = widgets.find<Cell>("cell-info_detail3");
        accuracy.set_string(action->accuracy == 0 ? "-" : std::to_string(action->accuracy));

        auto& style = widgets.find<Cell>("cell-info_detail4");
        style.set_string(Action::get_style_string(action->style));

        auto& contact = widgets.find<Cell>("cell-info_detail5");
        contact.set_string(action->contact ? "YES" : "NO");

        auto& cover = widgets.find<Cell>("cell-info_detail6");
        cover.set_string(Action::get_cover_string(action->cover));

        auto& detect = widgets.find<Cell>("cell-info_detail7");
        detect.set_string(action->detect ? "YES" : "NO");

        auto& move = widgets.find<Cell>("cell-info_detail8");
        move.set_string(Action::get_cover_string(action->move));
    }
    else if (skill) {
        name.set_string(skill->name);
        icon.set_texture(renderer.get_textures().get_skill());
        desc1.set_string(skill->desc1);
        desc2.set_string(skill->desc2);
        desc3.set_string(skill->desc3);
    }
}
