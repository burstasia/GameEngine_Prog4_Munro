#pragma once
#include "Scene.h"

namespace dae
{
	class Scene;

	class SceneObject
	{
	public:

		virtual void Update(float elapsedSec) = 0;
		virtual void Render() const = 0;

		SceneObject(Scene* pScene): m_pScene(pScene) {}
		virtual ~SceneObject() = default;

		SceneObject(const SceneObject& other) = delete;
		SceneObject(SceneObject&& other) = delete;
		SceneObject& operator=(const SceneObject& other) = delete;
		SceneObject& operator=(SceneObject&& other) = delete;


	protected:
		Scene *m_pScene;
	};
}
