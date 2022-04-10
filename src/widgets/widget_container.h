#pragma once

#include <map>
#include "button.h"
#include "cell.h"
#include "progress_bar.h"

class WidgetContainer {
public:
    WidgetContainer(const Renderer& renderer, const TextureContainer& textures) : renderer(renderer), textures(textures) {}

    void handle_event(const SDL_Event& e) const;
    void update() const;
    void draw() const;

    template <typename T>
    T& add(const std::string& id = "")
    {
        widgets.emplace_back(std::make_unique<T>(renderer, textures));
        if (!id.empty())
            indices.insert({ id, widgets.size() - 1 });
        return dynamic_cast<T&>(*widgets.back());
    }

    template <typename T>
    T& find(const std::string& id)
    {
        return dynamic_cast<T&>(*widgets.at(indices.at(id)));
    }

private:
    const Renderer& renderer;
    const TextureContainer& textures;
    std::vector<std::unique_ptr<Widget>> widgets;
    std::map<std::string, size_t> indices;
};
