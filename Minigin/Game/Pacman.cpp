#include "MiniginPCH.h"
#include "Pacman.h"
#include "../Components/SpriteComponent.h"
#include "../PacmanScene.h"
using namespace dae;

Pacman::Pacman(Scene* pScene):
	Actor(pScene, false),
	m_StartPos(256,448),
	m_IsHit(false),
	m_Lives(3),
	m_IsDead(false),
	m_Score(0)
{
	m_CurrScene = dynamic_cast<PacmanScene*>(pScene);


}

Pacman::~Pacman()
{

}

void Pacman::Update(float elapsedSec)
{
	m_EnemyPositions = m_CurrScene->GetEnemyPositions();
	CheckCollisionEnemies();
	Actor::Update(elapsedSec);
	m_Score = Actor::GetScore();
}

void Pacman::Render() const
{
	Actor::Render();
}

void dae::Pacman::Init()
{
	AddComponent(new SpriteComponent("pacman_move_anim.png", 50.0f, 50.0f, 5, 10));
	GetTransform()->ChangePosition((float)m_StartPos.x, (float)m_StartPos.y, 0.0f);
}

void dae::Pacman::IncreaseScore(int amount)
{
	m_Score += amount;
}

int dae::Pacman::GetScore() const
{
	return m_Score;
}

int dae::Pacman::GetLives() const
{
	return m_Lives;
}

bool dae::Pacman::GetDead()
{
	return m_IsDead;
}

void dae::Pacman::CheckCollisionEnemies()
{
	float x = GetTransform()->GetPosition().x;
	float deltaX = GetTransform()->GetPosition().x + 32.0f;

	float y = GetTransform()->GetPosition().y;
	float deltaY = GetTransform()->GetPosition().y + 32.0f;

	for (size_t i = 0; i < m_EnemyPositions.size(); i++)
	{
		if (!m_IsHit)
		{
			float xEnemy = (float)m_EnemyPositions.at(i).x;
			float deltaXEnemy = (float)m_EnemyPositions.at(i).x + 32;

			float yEnemy = (float)m_EnemyPositions.at(i).y;
			float deltaYEnemy = (float)m_EnemyPositions.at(i).y + 32;

			if ((x <= xEnemy && xEnemy <= deltaX) || (x <= deltaXEnemy && deltaXEnemy <= deltaX))
			{
				if ((y <= yEnemy && yEnemy <= deltaY) || (y <= deltaYEnemy && deltaYEnemy <= deltaY))
				{
					m_IsHit = true;
					ResetPacman();
				}
			}
		}
			
	}

}

void dae::Pacman::ResetPacman()
{

	GetTransform()->SetPosition((float)m_StartPos.x, (float)m_StartPos.y, 0);
	m_IsHit = false;
	m_Lives -= 1;

	m_CurrScene->UpdateHUD(m_Lives);

	if (m_Lives == 0)
	{
		m_IsDead = true;
		Death();
	}
}

void dae::Pacman::Death()
{
	GetTransform()->SetPosition(544.0f, 96.0f, 0.0f);
}
