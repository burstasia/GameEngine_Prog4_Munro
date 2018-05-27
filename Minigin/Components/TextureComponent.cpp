#include "MiniginPCH.h"
#include "TextureComponent.h"
#include "./BaseComponent.h"
#include "../ResourceManager.h"
#include "../Renderer.h"
#include "../Objects/GameObject.h"
#include <SDL.h>
namespace dae
{
	SDL_Texture * TextureComponent::GetSDLTexture() const
	{
		return m_Texture;
	}

	void TextureComponent::SetTexture(const std::string & file, float posX, float posY)
	{
		m_PosX = posX;
		m_PosY = posY;

		if(m_Texture != nullptr)
			SDL_DestroyTexture(m_Texture);

		m_Texture = ResourceManager::GetInstance().LoadTexture(file);
	}

	TextureComponent::TextureComponent(const std::string& file, float posX, float posY):
		m_PosX(posX),
		m_PosY(posY)
	{
		m_Texture = ResourceManager::GetInstance().LoadTexture(file);
	}

	TextureComponent::~TextureComponent()
	{
		SDL_DestroyTexture(m_Texture);
	}
	void TextureComponent::SetPosition(float x, float y)
	{
		m_PosX = x;
		m_PosY = y;
	}
	void TextureComponent::Init()
	{
	}
	void TextureComponent::Update(float elapsedSec)
	{
		UNREFERENCED_PARAMETER(elapsedSec);

		m_PosX = m_pGameObject->GetTransform()->GetPosition().x;
		m_PosY = m_pGameObject->GetTransform()->GetPosition().y;
	}
	void TextureComponent::Render()
	{
		Renderer::GetInstance().RenderTexture(*m_Texture, m_PosX, m_PosY);
	}
}

