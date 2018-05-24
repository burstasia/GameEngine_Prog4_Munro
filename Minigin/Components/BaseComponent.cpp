
#include "MiniginPCH.h"
#include "BaseComponent.h"
#include "./TransformComponent.h"
#include "../Objects/GameObject.h"

namespace dae
{
	BaseComponent::BaseComponent(void) :
		m_pGameObject(nullptr)
	{
	}


	BaseComponent::~BaseComponent()
	{
		//delete(m_pGameObject);
		//m_pGameObject = nullptr;
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

