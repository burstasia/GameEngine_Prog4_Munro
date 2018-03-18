#pragma once
#include "BaseComponent.h"
struct SDL_Texture;

namespace dae
{

	class TextureComponent final: public BaseComponent
	{
	public:
		SDL_Texture * GetSDLTexture() const;
		explicit TextureComponent(const std::string& file, float posX, float posY);
		~TextureComponent();

		void SetPosition(float x, float y);

		TextureComponent(const TextureComponent &) = delete;
		TextureComponent(TextureComponent &&) = delete;
		TextureComponent & operator= (const TextureComponent &) = delete;
		TextureComponent & operator= (const TextureComponent &&) = delete;
	protected:
		virtual void Init();
		virtual void Update(float elapsedSec);
		virtual void Render();

	private:
		SDL_Texture * m_Texture;
		float m_PosX;
		float m_PosY;
	};
}


