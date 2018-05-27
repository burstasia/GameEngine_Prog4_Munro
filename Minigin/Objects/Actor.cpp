#include "MiniginPCH.h"
#include "Actor.h"
#include "./Components/TransformComponent.h"
#include "./Scene.h"
#include "./Level.h"
#include <map>

namespace dae
{
	Actor::Actor(Scene* pScene, bool isEnemy) :
		GameObject(pScene),
		m_Direction(Direc::right),
		m_Speed(50.0f),
		m_IsEnemy(isEnemy),
		m_DistanceToTravel(0.0f),
		m_DistanceTravelled(0.0f),
		m_IsReachedGoal(false),
		m_IsGoalSet(false),
		m_Score(0),
		m_PillScore(10),
		m_SuperPillScore(15)
	{
	}


	Actor::~Actor()
	{
	}

	void Actor::Update(float elapsedSec)
	{
		if (m_IsEnemy) EnemyMovement(elapsedSec);
		else
		{
			NormalMovement(elapsedSec);

			SetPosition(elapsedSec, m_Speed);
		}
		
		GameObject::Update(elapsedSec);
	}

	void Actor::SetDirection(const Direc direction)
	{
		if(!m_IsEnemy)m_Direction = direction;
	}

	float Actor::GetSpeed()
	{
		return m_Speed;
	}

	int Actor::GetScore()
	{
		return m_Score;
	}

	void Actor::SetSpeed(float speed)
	{
		m_Speed = speed;
	}

	void Actor::NormalMovement(float elapsedSec)
	{
		UNREFERENCED_PARAMETER(elapsedSec);
		float futureX = GetTransform()->GetPosition().x;
		float futureY = GetTransform()->GetPosition().y;

		dae::TileType tile{};

		//check if tile i am on is pill
		if (!m_IsEnemy)
		{
			if (m_pScene->GetLevel()->GetTileType(futureX + 16, futureY + 16) == TileType::pill)
			{
				m_pScene->GetLevel()->ChangeTileType(futureX, futureY, TileType::empty);
				m_Score += m_PillScore;
			}
		}

		switch (m_Direction)
		{
		case 0:
			futureY -= 1;
			tile = m_pScene->GetLevel()->GetTileType(futureX, futureY, futureX + 31, futureY);
			break;

		case 1:
			futureY += 32;
			tile = m_pScene->GetLevel()->GetTileType(futureX, futureY, futureX + 31, futureY);
			break;

		case 2:
			futureX -= 1;
			tile = m_pScene->GetLevel()->GetTileType(futureX, futureY, futureX, futureY + 31);
			break;

		case 3:
			futureX += 32;
			tile = m_pScene->GetLevel()->GetTileType(futureX, futureY, futureX, futureY + 31);
			break;
		}


		if (tile == TileType::wall) m_Speed = 0.0f;
		else m_Speed = 50.0f;
	}

	void Actor::EnemyMovement(float elapsedSec)
	{
		UNREFERENCED_PARAMETER(elapsedSec);
		if (!m_IsGoalSet)
		{
			m_DistanceToTravel = (rand() % 10 + 1) * 32.0f;
			m_DistanceTravelled = 0.0f;

			SetDirectionEnemy();

			m_IsGoalSet = true;
		}
		if (m_DistanceTravelled <= m_DistanceToTravel)
		{
			m_DistanceTravelled += elapsedSec * m_Speed;
		}
		if (m_DistanceTravelled >= m_DistanceToTravel)
		{
			m_IsGoalSet = false;
			m_DistanceToTravel = 0.0f;
			m_DistanceTravelled = 0.0f;
		}

		NormalMovement(elapsedSec);

		SetPosition(elapsedSec, m_Speed);
		if (m_Speed <= 0.0f)
		{
			m_IsGoalSet = false;
		}
	}

	void Actor::SetPosition(float elapsedSec, float speed)
	{
		switch (m_Direction)
		{
		case 0:
			GetTransform()->ChangePosition(0.0f, -1.0f * (elapsedSec * speed), 0.0f);
			break;

		case 1:
			GetTransform()->ChangePosition(0.0f, (elapsedSec * speed), 0.0f);
			break;

		case 2:
			GetTransform()->ChangePosition(-1.0f *(elapsedSec * speed), 0.0f, 0.0f);
			break;

		case 3:
			GetTransform()->ChangePosition(((elapsedSec * speed)), 0.0f, 0.0f);
			break;
		}
	}
	void Actor::SetDirectionEnemy()
	{
		dae::TileType tile_forwards{};
		dae::TileType tile_backwards{};
		dae::TileType tile_left{};
		dae::TileType tile_right{};

		float x = GetTransform()->GetPosition().x + 16;
		float y = GetTransform()->GetPosition().y + 16;

		if (x > (float)m_pScene->GetLevel()->GetWidth()) x = (float)m_pScene->GetLevel()->GetWidth();
		if (x < 0) x = 0;
		if (y > (float)m_pScene->GetLevel()->GetHeight()) y = (float)m_pScene->GetLevel()->GetHeight();
		if (y < 0) y = 0;

		tile_forwards = m_pScene->GetLevel()->GetTileType(x, y - 32.0f);
		tile_backwards = m_pScene->GetLevel()->GetTileType(x, y + 32.0f);
		tile_left = m_pScene->GetLevel()->GetTileType(x - 32.0f, y);
		tile_right = m_pScene->GetLevel()->GetTileType(x + 32.0f, y);

		std::vector<Direc> tempDirecVec;

		if (tile_forwards != 1) tempDirecVec.push_back(Direc::up);
		if (tile_backwards != 1) tempDirecVec.push_back(Direc::down);
		if (tile_left != 1) tempDirecVec.push_back(Direc::left);
		if (tile_right != 1) tempDirecVec.push_back(Direc::right);

		if(tempDirecVec.size() == 0) tempDirecVec.push_back(Direc::down);

		m_Direction = tempDirecVec.at((int)(rand() % tempDirecVec.size()));

	}
}

