#pragma once
#include "Singleton.h"

namespace dae
{
	class Scene;
	class SceneManager final : public Singleton<SceneManager>
	{
	public:
		Scene & CreateScene(const std::string& name);

		void AddScene(std::shared_ptr<Scene> scene);
		void Update(float elapsedSec);
		void Render();
		void Init();

	private:
		std::vector<std::shared_ptr<Scene>> mScenes;
	};

}
