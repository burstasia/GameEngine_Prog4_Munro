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
	LoadLevel("../Data/level/level.json");
	m_pPacman = std::make_shared<Pacman>(this);
	Add(m_pPacman);

	m_pGhost_01 = std::make_shared<Ghost>(this);
	Add(m_pGhost_01);

	m_pGhost_02 = std::make_shared<Ghost>(this);
	Add(m_pGhost_02);

	m_pGhost_03 = std::make_shared<Ghost>(this);
	Add(m_pGhost_03);
}


PacmanScene::~PacmanScene()
{
}

void dae::PacmanScene::Update(float elapsedSec)
{
	UNREFERENCED_PARAMETER(elapsedSec);

	//HANDLE INPUT FOR PACMAN
	InputManager::GetInstance().ProcessInput();

	auto command  = InputManager::GetInstance().HandleInput();
	if (command) command->Execute(m_pPacman);

	Scene::Update(elapsedSec);

}

void dae::PacmanScene::Render() const
{
}

void dae::PacmanScene::Init()
{
	m_pPacman->Init();
	m_pGhost_01->Init("ghost_01.png");
	m_pGhost_02->Init("ghost_02.png");
	m_pGhost_03->Init("ghost_03.png");
}
