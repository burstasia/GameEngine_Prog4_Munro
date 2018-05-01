#include "MiniginPCH.h"
#include "TextComponent.h"

#include "Renderer.h"
#include "Font.h"
#include "Texture2D.h"
#include "GameObject.h"
#include "BaseComponent.h"
#include "./TransformComponent.h"

namespace dae
{

	TextComponent::TextComponent(const std::string & text, const std::string& fullPath, unsigned int size, float posX, float posY) :
		mText(text),
		m_PosX(posX),
		m_PosY(posY)
	{
		mFont = ResourceManager::GetInstance().LoadFont(fullPath, size);

		SetText(text);
	}

	TextComponent::~TextComponent()
	{
		SDL_DestroyTexture(mTexture);
	}
	void TextComponent::SetText(const std::string & text)
	{
		mText = text;

		const SDL_Color color = { 255,255,255 }; // only white text is supported now
		const auto surf = TTF_RenderText_Blended(mFont->GetFont(), mText.c_str(), color);
		if (surf == nullptr) {
			std::stringstream ss; ss << "Render text failed: " << SDL_GetError();
			throw std::runtime_error(ss.str().c_str());
		}
		auto texture = SDL_CreateTextureFromSurface(Renderer::GetInstance().GetSDLRenderer(), surf);
		if (texture == nullptr) {
			std::stringstream ss; ss << "Create text texture from surface failed: " << SDL_GetError();
			throw std::runtime_error(ss.str().c_str());
		}
		SDL_FreeSurface(surf);
		mTexture = texture;
	}
	void TextComponent::Init()
	{
	}
	void TextComponent::Update(float elapsedSec)
	{
		UNREFERENCED_PARAMETER(elapsedSec);

		m_PosX = m_pGameObject->GetTransform()->GetPosition().x;
		m_PosY = m_pGameObject->GetTransform()->GetPosition().y;

	}
	void TextComponent::Render()
	{
		if (mTexture != nullptr)
		{
			
			Renderer::GetInstance().RenderTexture(*mTexture, m_PosX, m_PosY);
		}
	}
}

