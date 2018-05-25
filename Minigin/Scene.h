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
		explicit Scene(const std::string& name);

		void Add(const std::shared_ptr<SceneObject>& object);

		virtual void Update(float elapsedSec);
		void Render() const;
		virtual void Init() {}


		//getter for level
		void LoadLevel(const std::string& path);
		Level* GetLevel() const { return m_pLevel; }
		//draw level
		~Scene();
		Scene(const Scene& other) = delete;
		Scene(Scene&& other) = delete;
		Scene& operator=(const Scene& other) = delete;
		Scene& operator=(Scene&& other) = delete;

	private: 
		

		std::string mName{};
		std::vector < std::shared_ptr<SceneObject>> mObjects{};

		//TODO: level memeber var
		Level * m_pLevel;

		static unsigned int idCounter; 
	};

}
