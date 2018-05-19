#pragma once


namespace dae
{
	class Scene;

	class SceneObject
	{
	public:

		virtual void Update(float elapsedSec) = 0;
		virtual void Render() const = 0;

		SceneObject(const Scene& scene): m_pScene(scene) {}
		virtual ~SceneObject() = default;
		SceneObject(const SceneObject& other) = delete;
		SceneObject(SceneObject&& other) = delete;
		SceneObject& operator=(const SceneObject& other) = delete;
		SceneObject& operator=(SceneObject&& other) = delete;


	protected:
		const Scene & m_pScene;
	};
}
