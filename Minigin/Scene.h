#pragma once
#include "SceneManager.h"

namespace dae
{
	class SceneObject;
	class Level;

	class Scene
	{
		friend Scene& SceneManager::CreateScene(const std::string& name);
	public:
		void Add(const std::shared_ptr<SceneObject>& object);

		void Update(float elapsedSec);
		void Render() const;

		//getter for level
		Level* GetLevel() const { return m_pLevel; }
		//draw level
		~Scene();
		Scene(const Scene& other) = delete;
		Scene(Scene&& other) = delete;
		Scene& operator=(const Scene& other) = delete;
		Scene& operator=(Scene&& other) = delete;

	private: 
		explicit Scene(const std::string& name);

		std::string mName{};
		std::vector < std::shared_ptr<SceneObject>> mObjects{};

		//TODO: level memeber var
		Level * m_pLevel;

		static unsigned int idCounter; 
	};

}
