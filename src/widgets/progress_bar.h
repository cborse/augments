//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#pragma once

#include "widget.h"

class ProgressBar : public Widget {
public:
    explicit ProgressBar(const Renderer& renderer) : Widget(renderer) {}

    virtual bool handle_event(const SDL_Event& e) override;
    virtual void update() override {}
    virtual void draw() const override;

    void set_bounds(const SDL_Rect& bounds);
    void set_value(float value);
    void set_visibility(bool visible);

    ProgressBar& with_bounds(const SDL_Rect& bounds);
    ProgressBar& with_value(float value);
    ProgressBar& with_visibility(bool visible);

private:
    bool visible = true;
    SDL_Rect bounds = {};
    float value = 0.f;
};
