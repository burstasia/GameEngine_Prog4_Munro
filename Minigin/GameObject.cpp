#include "MiniginPCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "./Components/TransformComponent.h"
#include "./Components/BaseComponent.h"
#include "Scene.h"
namespace dae
{
	GameObject::GameObject(const Scene& scene) :
		SceneObject(scene)
	{
		m_Transform.m_pGameObject = this;
	}
	GameObject::~GameObject()
	{
		//delte components
		for (BaseComponent* pComp : m_pComponents)
		{
			if (pComp != 0)
			{
				delete(pComp);
				pComp = 0;
			}
		}
	}

	void GameObject::Update(float elapsedSec)
	{
		for (BaseComponent* pComp : m_pComponents)
		{
			pComp->Update(elapsedSec);
		}
	}

	void GameObject::Render() const
	{
		for (BaseComponent* pComp : m_pComponents)
		{
			pComp->Render();
		}
	}

	void GameObject::AddComponent(BaseComponent * pComp)
	{
		m_pComponents.push_back(pComp);
		pComp->m_pGameObject = this;
	}

	void GameObject::RemoveComponent(BaseComponent * pComp)
	{
		auto it = find(m_pComponents.begin(), m_pComponents.end(), pComp);
		m_pComponents.erase(it);
		pComp->m_pGameObject = nullptr;
	}

	TransformComponent* GameObject::GetTransform()
	{
		return &m_Transform;
	}
}

