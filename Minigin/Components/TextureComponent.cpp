#include "MiniginPCH.h"
#include "TextureComponent.h"
#include "./BaseComponent.h"
#include "../ResourceManager.h"
#include "../Renderer.h"
#include <SDL.h>
namespace dae
{
	SDL_Texture * TextureComponent::GetSDLTexture() const
	{
		return m_Texture;
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
	}
	void TextureComponent::Render()
	{
		Renderer::GetInstance().RenderTexture(*m_Texture, m_PosX, m_PosY);
	}
}

