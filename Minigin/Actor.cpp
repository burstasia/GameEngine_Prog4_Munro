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

		/*if (futureX <= 0.1f || futureY <= 0.1f)
		{
			m_IsStuck = true;
		}*/

		if (m_Direction == Direc::down)
		{
			futureY -= 32;
			tile = m_pScene.GetLevel()->GetTileType(futureX, futureY);
		}
		else if (m_Direction == Direc::up)
		{
			futureY += 32;
			tile = m_pScene.GetLevel()->GetTileType(futureX, futureY);
		}
		else if (m_Direction == Direc::left)
		{
			futureX -= 32;
			tile = m_pScene.GetLevel()->GetTileType(futureX, futureY);
		}
		else if (m_Direction == Direc::right)
		{
			futureX += 32;
			tile = m_pScene.GetLevel()->GetTileType(futureX, futureY);
		}
		
		if (tile == TileType::wall) m_Speed = 0.0f;
		else m_Speed = 50.0f;
		//TODO make switch instead of if
		//TODO make helper move function
	
			if (m_Direction == 0) // UP
			{
				GetTransform()->SetPosition(0.0f, -1.0f * (elapsedSec * m_Speed), 0.0f);
			}
			else if (m_Direction == 1) // DOWN
			{
				GetTransform()->SetPosition(0.0f, (elapsedSec * m_Speed), 0.0f);
			}
			else if (m_Direction == 2) // LEFT
			{
				GetTransform()->SetPosition(-1.0f *(elapsedSec * m_Speed), 0.0f, 0.0f);
			}
			else if (m_Direction == 3) // RIGHT
			{
				GetTransform()->SetPosition(((elapsedSec * m_Speed)), 0.0f, 0.0f);
			}
	
		

		GameObject::Update(elapsedSec);
	}

	void Actor::SetDirection(const Direc direction)
	{
		m_Direction = direction;
	}
}

