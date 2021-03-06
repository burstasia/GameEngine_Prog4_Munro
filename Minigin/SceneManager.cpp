#include "MiniginPCH.h"
#include "SceneManager.h"
#include "Scene.h"


void dae::SceneManager::Update(float elapsedSec)
{
	for(auto scene : mScenes)
	{
		scene->Update(elapsedSec);
	}
}

void dae::SceneManager::Render()
{
	for (const auto scene : mScenes)
	{
		scene->Render();
	}
}

void dae::SceneManager::Init()
{
	for (const auto scene : mScenes)
	{
		scene->Init();
	}
}

dae::Scene& dae::SceneManager::CreateScene(const std::string& name)
{
	const auto scene = std::shared_ptr<Scene>(new Scene(name));
	mScenes.push_back(scene);
	return *scene;
}

void dae::SceneManager::AddScene(std::shared_ptr<Scene> scene)
{
	mScenes.push_back(scene);
}
