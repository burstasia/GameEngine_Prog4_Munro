
#include "MiniginPCH.h"
#include "BaseComponent.h"
#include "./TransformComponent.h"
#include "../GameObject.h"

namespace dae
{
	BaseComponent::BaseComponent(void) :
		m_pGameObject(nullptr)
	{
	}


	BaseComponent::~BaseComponent()
	{
	}

	GameObject * BaseComponent::GetGameObject() const
	{
		return m_pGameObject;
	}

	TransformComponent * BaseComponent::GetTransform() const
	{
		return m_pGameObject->GetTransform();
	}
}

