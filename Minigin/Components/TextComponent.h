#pragma once
#pragma warning(push)
#pragma warning (disable:4201)
#include <glm/vec3.hpp>
#pragma warning(pop)
#include "BaseComponent.h"
#include "ResourceManager.h"
#include "Font.h"
#include "Texture2D.h"

namespace dae
{
	class TextComponent final : public BaseComponent
	{
	public:
		explicit TextComponent(const std::string& text, const std::string& fullPath, unsigned int size, float posX, float posY);
		~TextComponent();


		void SetText(const std::string& text);
		void SetPosition(float x, float y);

		TextComponent(const TextComponent &) = delete;
		TextComponent(TextComponent &&) = delete;
		TextComponent & operator= (const TextComponent &) = delete;
		TextComponent & operator= (const TextComponent &&) = delete;

	protected:

		void Init() override;
		void Update(float elapsedSec) override;
		void Render() override;

	private:
		std::string mText;
		std::shared_ptr<Font> mFont;
		SDL_Texture* mTexture;

		float m_PosX;
		float m_PosY;
	};
}


