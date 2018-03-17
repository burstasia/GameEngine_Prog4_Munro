#include "MiniginPCH.h"
#include "TextureComponent.h"
#include "./BaseComponent.h"
#include <SDL.h>
namespace dae
{
	SDL_Texture * TextureComponent::GetSDLTexture() const
	{
		return m_Texture;
	}

	TextureComponent::TextureComponent(SDL_Texture * texture)
	{
		m_Texture = texture;
	}

	TextureComponent::~TextureComponent()
	{
		SDL_DestroyTexture(m_Texture);
	}
}

