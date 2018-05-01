#include "MiniginPCH.h"
#include "Actor.h"
#include "./Components/TransformComponent.h"


Actor::Actor():
	m_Direction(Direc::left),
	m_Speed(10.0f)
{
}


Actor::~Actor()
{
}

void Actor::Update(float elapsedSec)
{
	//TODO make switch instead of if
	//TODO make helper move function
	if (m_Direction == 0) // UP
	{
		GetTransform()->SetPosition(0.0f, (elapsedSec * m_Speed), 0.0f);
	}
	else if (m_Direction == 1) // DOWN
	{
		GetTransform()->SetPosition(0.0f, -1.0f * (elapsedSec * m_Speed), 0.0f);
	}
	else if (m_Direction == 2) // RIGHT
	{
		GetTransform()->SetPosition((elapsedSec * m_Speed), 0.0f , 0.0f);
	}
	else if (m_Direction == 3) // LEFT
	{
		GetTransform()->SetPosition(-1.0f * (elapsedSec * m_Speed), 0.0f, 0.0f);
	}

}

void Actor::SetDirection(const Direc direction)
{
	m_Direction = direction;
}
