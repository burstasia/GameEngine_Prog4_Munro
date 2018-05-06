#include "MiniginPCH.h"
#include "SpriteComponent.h"
#include "./BaseComponent.h"
#include "../ResourceManager.h"
#include "../Renderer.h"
#include "GameObject.h"
#include <SDL.h>

namespace dae
{
	SpriteComponent::SpriteComponent(const std::string& file, float posX, float posY, int numFrames, int numFramesPerSec):
		m_PosX(posX),
		m_PosY(posY),
		m_NumFrames(numFrames),
		m_FramesPerSec(numFramesPerSec)
	{
		m_Texture = ResourceManager::GetInstance().LoadTexture(file);
		m_Animating = true;

		//Damn dummy values and warning levels are ruining my life
		int something = SDL_QueryTexture(m_Texture, NULL, NULL, &m_WidthTexture, &m_HeightTexture);

		m_WidthFrame = m_WidthTexture / numFrames;
		m_HeightFrame = m_HeightTexture;

		m_CurrFrame = something;
	}


	SpriteComponent::~SpriteComponent()
	{
	}

	void SpriteComponent::SetPosition(float x, float y)
	{
		m_PosX = x;
		m_PosY = y;

	}

	void SpriteComponent::Init()
	{
	}

	void SpriteComponent::Update(float elapsedSec)
	{
		m_PosX = m_pGameObject->GetTransform()->GetPosition().x;
		m_PosY = m_pGameObject->GetTransform()->GetPosition().y;

		if (m_Animating)
		{
			m_Timer += elapsedSec;

			if (m_Timer > (1.0f / (m_FramesPerSec)))
			{
				m_Timer = 0.0f;

				++m_CurrFrame;
				if (m_CurrFrame > (m_NumFrames - 1)) m_CurrFrame = 0;
			}

		}
	}

	void SpriteComponent::Render()
	{

		Renderer::GetInstance().RenderTexture(*m_Texture, m_PosX, m_PosY,
			m_WidthTexture, m_HeightTexture,	float( m_CurrFrame * m_WidthFrame), 
			0.0f, m_WidthFrame, m_HeightFrame);
	}

}

