#include "MiniginPCH.h"
#include "TransformComponent.h"
#include "./BaseComponent.h"

namespace dae
{
	TransformComponent::TransformComponent(void):
		BaseComponent()
	{
		m_Position = glm::vec3(0, 0, 0);
	}

	TransformComponent::~TransformComponent()
	{
	}

	void TransformComponent::Update(float elapsedSec)
	{
		UNREFERENCED_PARAMETER(elapsedSec);
	}

	void TransformComponent::Render()
	{
	}

	void TransformComponent::Init()
	{
	}

	const glm::vec3 & TransformComponent::GetPosition() const
	{
		return m_Position;
	}

	void TransformComponent::ChangePosition(float x, float y, float z)
	{
		m_Position.x += x;
		m_Position.y += y;
		m_Position.z += z;
	}
	void TransformComponent::SetPosition(float x, float y, float z)
	{
		m_Position.x = x;
		m_Position.y = y;
		m_Position.z = z;
	}
}


