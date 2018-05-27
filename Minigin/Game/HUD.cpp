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
	AddComponent(new TextComponent("Lives : 3", "Lingua.otf", 20, 544.0f, 0.0f));
	//AddComponent(new TextComponent("Score : 0", "Lingua.otf", 20, 544.0f, 64.0f));
}

void dae::HUD::IncreaseScore(int score)
{
	UNREFERENCED_PARAMETER(score);
	/*m_Score += score;
	auto text = dynamic_cast<TextComponent*>(m_pComponents.at(1));
	text->GetTransform()->SetPosition(544.0f, 0.0f, 0.0f);
	std::string textasd{ "Score : "};

	text->SetText(textasd);*/
}

void dae::HUD::SetLives(int lives)
{
	UNREFERENCED_PARAMETER(lives);
	m_Lives = lives;

	if (m_Lives >= 0)
	{
		auto text = dynamic_cast<TextComponent*>(m_pComponents.at(0));
		text->GetTransform()->SetPosition(544.0f, 64.0f, 0.0f);
		std::string textasdf{ "Lives : " + std::to_string(m_Lives) };

		text->SetText(textasdf);
	}
	
}
