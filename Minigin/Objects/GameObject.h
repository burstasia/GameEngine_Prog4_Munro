#pragma once
#include <memory>

#include "Transform.h"
#include "Texture2D.h"
#include "SceneObject.h"
#include "./Components/TransformComponent.h"




namespace dae
{
	class Scene;
	class BaseComponent;
	class TransformComponent;

	class GameObject : public SceneObject
	{
	public:
		void Update(float elapsedSec) override;
		void Render() const override;

		void AddComponent(BaseComponent* pComp);
		void RemoveComponent(BaseComponent* pComp);

		TransformComponent* GetTransform();

		GameObject(const Scene& scene);
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

	private:
		TransformComponent m_Transform;

		//I choose to use a vector of BaseComponents because if I were to create
		//a set amount of components in a GameObject class such as:
		//InputComponent* input;
		//PhysicsComponent* physics;
		//GraphicsComponent* graphics;

		//then i would be bound to having these components in my game object class
		//and if I don't want a graphics component (for example) 
		//then I would be forced to set it to a nullptr 
		//which I think is worse than having a vector of components that inherit 
		//from BaseComponent
		std::vector<BaseComponent*> m_pComponents;
	};
}
