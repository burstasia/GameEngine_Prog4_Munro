#include "MiniginPCH.h"
#include "Pacman.h"
#include "../Components/SpriteComponent.h"
#include "../PacmanScene.h"
using namespace dae;

Pacman::Pacman(Scene* pScene):
	Actor(pScene, false),
	m_StartPos(256,256),
	m_IsHit(false),
	m_Lives(3)
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
}
