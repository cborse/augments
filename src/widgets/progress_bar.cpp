#include "progress_bar.h"

bool ProgressBar::handle_event(const SDL_Event& e)
{
    return false;
}

void ProgressBar::draw() const
{
    if (visible) {
        renderer.fill_rect(bounds, { 15, 15, 14 });
        int width = (int)(value * (bounds.w - 4.f));
        renderer.fill_rect({ bounds.x + 2, bounds.y + 2, width > 0 ? width : 1, bounds.h - 4 }, { 118, 66, 138 });
    }
}

void ProgressBar::set_bounds(const SDL_Rect& bounds)
{
    this->bounds = bounds;
}

void ProgressBar::set_value(float value)
{
    this->value = value;
}

void ProgressBar::set_visibility(bool visible)
{
    this->visible = visible;
}

ProgressBar& ProgressBar::with_bounds(const SDL_Rect& bounds)
{
    set_bounds(bounds);
    return *this;
}

ProgressBar& ProgressBar::with_value(float value)
{
    set_value(value);
    return *this;
}

ProgressBar& ProgressBar::with_visibility(bool visible)
{
    set_visibility(visible);
    return *this;
}
