#include "MiniginPCH.h"
#include "HUD.h"
#include "../Components/TextComponent.h"
#include "../Objects/GameObject.h"

using namespace dae;

HUD::HUD(Scene* pScene):
	GameObject(pScene),
	m_Score(0),
	m_Lives(3)
{
}


HUD::~HUD()
{
}

void dae::HUD::Update(float elapsedSec)
{

	GameObject::Update(elapsedSec);
}

void dae::HUD::Render() const
{
	GameObject::Render();
}

void dae::HUD::Init()
{
	AddComponent(new TextComponent("Lives : 3", "Lingua.otf", 20, 512.0f, 64.0f));
	AddComponent(new TextComponent("Score : 0", "Lingua.otf", 20, 512.0f, 0.0f));
}

void dae::HUD::SetScore(int score)
{
	UNREFERENCED_PARAMETER(score);

	if (score != m_Score)
	{
		m_Score = score;

		auto text = static_cast<TextComponent*>(m_pComponents.at(1));

		text->SetText("Score : " + std::to_string(score));
	}
	
}

void dae::HUD::SetLives(int lives)
{
	UNREFERENCED_PARAMETER(lives);
	m_Lives = lives;

	if (m_Lives >= 0)
	{
		auto text = static_cast<TextComponent*>(m_pComponents.at(0));
		
		text->SetText("Lives : " + std::to_string(m_Lives));
	}
	
}
