#pragma once
#pragma warning(push)
#pragma warning (disable:4201)
#include <glm/vec3.hpp>
#pragma warning(pop)
#include "BaseComponent.h"

namespace dae
{
	
	class TransformComponent final : public BaseComponent
	{
	public:
		TransformComponent(void);
		virtual ~TransformComponent();

		const glm::vec3& GetPosition() const;
		void SetPosition(float x, float y, float z);
	private:
		glm::vec3 m_Position;
	}; 

}


