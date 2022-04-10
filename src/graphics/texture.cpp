#include "texture.h"

Texture::Texture(SDL_Texture* texture)
    : texture(texture)
{
    SDL_QueryTexture(texture, nullptr, nullptr, &size.x, &size.y);
}

Texture::Texture(Texture&& other) noexcept
{
    texture = other.texture;
    size = other.size;

    other.texture = nullptr;
}

Texture::~Texture()
{
    SDL_DestroyTexture(texture);
}

Texture& Texture::operator=(Texture&& other) noexcept
{
    if (texture != other.texture) {
        SDL_DestroyTexture(texture);
        texture = other.texture;
        size = other.size;
    }

    other.texture = nullptr;
    return *this;
}

const SDL_Point& Texture::get_size() const
{
    return size;
}

void Texture::set_alpha(uint8_t alpha) const
{
    SDL_SetTextureAlphaMod(texture, alpha);
}
