#include "MiniginPCH.h"
#include "TransformComponent.h"
#include "./BaseComponent.h"

namespace dae
{
	TransformComponent::TransformComponent(void)
	{
	}

	TransformComponent::~TransformComponent()
	{
	}

	const glm::vec3 & TransformComponent::GetPosition() const
	{
		return m_Position;
	}

	void TransformComponent::SetPosition(float x, float y, float z)
	{
		m_Position.x = x;
		m_Position.y = y;
		m_Position.z = z;
	}
}


