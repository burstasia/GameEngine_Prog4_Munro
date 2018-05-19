#include "MiniginPCH.h"
#include "Actor.h"
#include "./Components/TransformComponent.h"
#include "./Scene.h"
#include "./Level.h"

namespace dae
{
	Actor::Actor(const Scene& scene) :
		GameObject(scene),
		m_Direction(Direc::left),
		m_Speed(50.0f)
	{
	}


	Actor::~Actor()
	{
	}

	void Actor::Update(float elapsedSec)
	{
		dae::TileType tile = m_pScene.GetLevel()->GetTileType(0.0f, 0.0f);

		
		temp = tile;

		//TODO make switch instead of if
		//TODO make helper move function
		if (m_Direction == 0) // UP
		{
			GetTransform()->SetPosition(0.0f, -1.0f * (elapsedSec * m_Speed), 0.0f );
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

