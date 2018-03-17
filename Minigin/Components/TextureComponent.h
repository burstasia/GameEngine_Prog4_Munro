#pragma once
#include "BaseComponent.h"
struct SDL_Texture;

namespace dae
{

	class TextureComponent final: public BaseComponent
	{
	public:
		SDL_Texture * GetSDLTexture() const;
		explicit TextureComponent(SDL_Texture* texture);
		~TextureComponent();

		TextureComponent(const TextureComponent &) = delete;
		TextureComponent(TextureComponent &&) = delete;
		TextureComponent & operator= (const TextureComponent &) = delete;
		TextureComponent & operator= (const TextureComponent &&) = delete;

	private:
		SDL_Texture* m_Texture;
	};
}


