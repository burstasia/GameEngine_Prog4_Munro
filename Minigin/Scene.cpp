#include "MiniginPCH.h"
#include "Scene.h"
#include "GameObject.h"
#include "Level.h"
#include "LevelLoader.h"

unsigned int dae::Scene::idCounter = 0;

dae::Scene::Scene(const std::string& name) : mName(name) 
{
	

}

dae::Scene::~Scene()
{
	delete(m_pLevel);
	m_pLevel = nullptr;

}

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
	m_pLevel->Render();
	for (const auto gameObject : mObjects)
	{
		gameObject->Render();
	}
	
	
}

void dae::Scene::LoadLevel(const std::string & path)
{
	auto levelLoader = new LevelLoader();

	m_pLevel = levelLoader->LoadLevel(path);
}

