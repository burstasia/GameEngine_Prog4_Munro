#include "MiniginPCH.h"
#include "Actor.h"
#include "./Components/TransformComponent.h"
#include "./Scene.h"
#include "./Level.h"

namespace dae
{
	Actor::Actor(const Scene& scene) :
		GameObject(scene),
		m_Direction(Direc::right),
		m_Speed(50.0f)
	{
	}


	Actor::~Actor()
	{
	}

	void Actor::Update(float elapsedSec)
	{
		float futureX = GetTransform()->GetPosition().x;
		float futureY = GetTransform()->GetPosition().y;

		dae::TileType tile{};

		if (m_Direction == Direc::down)
		{
			futureY += 32;
			tile = m_pScene.GetLevel()->GetTileType(futureX, futureY, futureX + 31, futureY);
		}
		else if (m_Direction == Direc::up)
		{
			futureY -= 1;
			tile = m_pScene.GetLevel()->GetTileType(futureX, futureY, futureX + 31, futureY);
		}
		else if (m_Direction == Direc::left)
		{
			futureX -= 1;
			tile = m_pScene.GetLevel()->GetTileType(futureX, futureY, futureX, futureY + 31);
		}
		else if (m_Direction == Direc::right)
		{
			futureX += 32;
			tile = m_pScene.GetLevel()->GetTileType(futureX, futureY, futureX, futureY + 31);
		}
		
		if (tile == TileType::wall) m_Speed = 0.0f;
		else m_Speed = 50.0f;

		SetPosition(elapsedSec);
		//TODO make switch instead of if
		//TODO make helper move function
	
			//if (m_Direction == 0) // UP
			//{
			//	GetTransform()->SetPosition(0.0f, -1.0f * (elapsedSec * m_Speed), 0.0f);
			//}
			//else if (m_Direction == 1) // DOWN
			//{
			//	GetTransform()->SetPosition(0.0f, (elapsedSec * m_Speed), 0.0f);
			//}
			//else if (m_Direction == 2) // LEFT
			//{
			//	GetTransform()->SetPosition(-1.0f *(elapsedSec * m_Speed), 0.0f, 0.0f);
			//}
			//else if (m_Direction == 3) // RIGHT
			//{
			//	GetTransform()->SetPosition(((elapsedSec * m_Speed)), 0.0f, 0.0f);
			//}
	
		

		GameObject::Update(elapsedSec);
	}

	void Actor::SetDirection(const Direc direction)
	{
		m_Direction = direction;
	}

	float Actor::GetSpeed()
	{
		return m_Speed;
	}

	void Actor::SetSpeed(float speed)
	{
		m_Speed = speed;
	}

	void Actor::NomralMovement(float elapsedSec)
	{
		UNREFERENCED_PARAMETER(elapsedSec);
	}

	void Actor::EnemyMovement(float elapsedSec)
	{
		UNREFERENCED_PARAMETER(elapsedSec);
	}

	void Actor::SetPosition(float elapsedSec)
	{
		switch (m_Direction)
		{
		case 0:
			GetTransform()->SetPosition(0.0f, -1.0f * (elapsedSec * m_Speed), 0.0f);
			break;

		case 1:
			GetTransform()->SetPosition(0.0f, (elapsedSec * m_Speed), 0.0f);
			break;

		case 2:
			GetTransform()->SetPosition(-1.0f *(elapsedSec * m_Speed), 0.0f, 0.0f);
			break;

		case 3:
			GetTransform()->SetPosition(((elapsedSec * m_Speed)), 0.0f, 0.0f);
			break;
		}
	}
}

