#include "MiniginPCH.h"
#include "PacmanScene.h"
#include "./InputManager.h"
#include "Objects\Actor.h"
#include "./SceneObject.h"
#include "./Objects/GameObject.h"

using namespace dae;

PacmanScene::PacmanScene()
	:Scene("pacmanScene")

{
	auto pac = std::make_shared<Pacman>(this);
	//SceneManager::GetInstance().AddScene(*this);
	Add(pac);
}


PacmanScene::~PacmanScene()
{
}

void dae::PacmanScene::Update(float elapsedSec)
{
	UNREFERENCED_PARAMETER(elapsedSec);
	auto command  = InputManager::GetInstance().HandleInput();
	if (command) command->Execute(m_pPacman);


}

void dae::PacmanScene::Render() const
{
}

void dae::PacmanScene::Init()
{

}
