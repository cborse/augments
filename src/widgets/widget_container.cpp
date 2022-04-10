#include "widget_container.h"

void WidgetContainer::handle_event(const SDL_Event& e) const
{
    for (const auto& widget : widgets) {
        if (widget->handle_event(e))
            return;
    }
}

void WidgetContainer::update() const
{
    for (const auto& widget : widgets)
        widget->update();
}

void WidgetContainer::draw() const
{
    for (const auto& widget : widgets)
        widget->draw();
}
