#include "MiniginPCH.h"
#include "Scene.h"
#include "GameObject.h"
#include "Level.h"
#include "LevelLoader.h"

unsigned int dae::Scene::idCounter = 0;

dae::Scene::Scene(const std::string& name) : mName(name) 
{
	auto levelLoader = new LevelLoader();

	m_pLevel = levelLoader->LoadLevel("../Data/level/level.json");

}

dae::Scene::~Scene() = default;

void dae::Scene::Add(const std::shared_ptr<SceneObject>& object)
{
	mObjects.push_back(object);
}

void dae::Scene::Update(float elapsedSec)
{
	for(auto gameObject : mObjects)
	{
		gameObject->Update(elapsedSec);
	}
	m_pLevel->Update(elapsedSec);
}

void dae::Scene::Render() const
{
	for (const auto gameObject : mObjects)
	{
		gameObject->Render();
	}

	m_pLevel->Render();
}

