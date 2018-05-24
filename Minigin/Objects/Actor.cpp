#include "MiniginPCH.h"
#include "Actor.h"
#include "./Components/TransformComponent.h"
#include "./Scene.h"
#include "./Level.h"
#include <map>

namespace dae
{
	Actor::Actor(const Scene& scene, bool isEnemy) :
		GameObject(scene),
		m_Direction(Direc::right),
		m_Speed(50.0f),
		m_IsEnemy(isEnemy),
		m_DistanceToTravel(0.0f),
		m_DistanceTravelled(0.0f),
		m_IsReachedGoal(false),
		m_IsGoalSet(false)
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
			if(m_pScene.GetLevel()->GetTileType(futureX + 16, futureY + 16) == TileType::pill) m_pScene.GetLevel()->ChangeTileType(futureX, futureY, TileType::empty);
		}

		switch (m_Direction)
		{
		case 0:
			futureY -= 1;
			tile = m_pScene.GetLevel()->GetTileType(futureX, futureY, futureX + 31, futureY);
			break;

		case 1:
			futureY += 32;
			tile = m_pScene.GetLevel()->GetTileType(futureX, futureY, futureX + 31, futureY);
			break;

		case 2:
			futureX -= 1;
			tile = m_pScene.GetLevel()->GetTileType(futureX, futureY, futureX, futureY + 31);
			break;

		case 3:
			futureX += 32;
			tile = m_pScene.GetLevel()->GetTileType(futureX, futureY, futureX, futureY + 31);
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
			GetTransform()->SetPosition(0.0f, -1.0f * (elapsedSec * speed), 0.0f);
			break;

		case 1:
			GetTransform()->SetPosition(0.0f, (elapsedSec * speed), 0.0f);
			break;

		case 2:
			GetTransform()->SetPosition(-1.0f *(elapsedSec * speed), 0.0f, 0.0f);
			break;

		case 3:
			GetTransform()->SetPosition(((elapsedSec * speed)), 0.0f, 0.0f);
			break;
		}
	}
	void Actor::SetDirectionEnemy()
	{
		dae::TileType tile_forwards{};
		dae::TileType tile_backwards{};
		dae::TileType tile_left{};
		dae::TileType tile_right{};

		float x = GetTransform()->GetPosition().x;
		float y = GetTransform()->GetPosition().y;

		tile_forwards = m_pScene.GetLevel()->GetTileType(x, y - 32.0f);
		tile_backwards = m_pScene.GetLevel()->GetTileType(x, y + 32.0f);
		tile_left = m_pScene.GetLevel()->GetTileType(x - 32.0f, y);
		tile_right = m_pScene.GetLevel()->GetTileType(x + 32.0f, y);

		std::vector<Direc> tempDirecVec;

		if (tile_forwards != 1) tempDirecVec.push_back(Direc::up);
		if (tile_backwards != 1) tempDirecVec.push_back(Direc::down);
		if (tile_left != 1) tempDirecVec.push_back(Direc::left);
		if (tile_right != 1) tempDirecVec.push_back(Direc::right);

		m_Direction = tempDirecVec.at((int)(rand() % tempDirecVec.size()));

	}
}

