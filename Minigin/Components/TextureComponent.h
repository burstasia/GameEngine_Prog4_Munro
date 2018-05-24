#pragma once
#include "BaseComponent.h"
struct SDL_Texture;

namespace dae
{

	class TextureComponent final: public BaseComponent
	{
	public:
		SDL_Texture * GetSDLTexture() const;
		void SetTexture(const std::string& file, float posX, float posY);
		explicit TextureComponent(const std::string& file, float posX, float posY);
		~TextureComponent();

		void SetPosition(float x, float y);

		TextureComponent(const TextureComponent &) = delete;
		TextureComponent(TextureComponent &&) = delete;
		TextureComponent & operator= (const TextureComponent &) = delete;
		TextureComponent & operator= (const TextureComponent &&) = delete;
	protected:
		virtual void Init()override;
		virtual void Update(float elapsedSec)override;
		virtual void Render() override;

	private:
		SDL_Texture * m_Texture;
		float m_PosX;
		float m_PosY;
	};
}


