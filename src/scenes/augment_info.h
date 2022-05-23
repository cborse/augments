#pragma once

#include "cache/action.h"
#include "cache/skill.h"
#include "widgets/widget_container.h"

class AugmentInfo {
public:
    AugmentInfo(const Renderer& renderer);

    void draw() const;
    void set_augment(const Action& action);
    void set_augment(const Skill& skill);

private:
    void refresh();

    static std::string get_cover_string(CoverID cover);
    static std::string get_style_string(StyleID style);

    const Action* action = nullptr;
    const Skill* skill = nullptr;
    const Renderer& renderer;
    WidgetContainer widgets;
};
