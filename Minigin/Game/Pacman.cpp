#include "MiniginPCH.h"
#include "Pacman.h"
#include "../Components/SpriteComponent.h"
#include "../PacmanScene.h"
using namespace dae;

Pacman::Pacman(Scene* pScene):
	Actor(pScene, false),
	m_StartPos(256,256)
{
	m_CurrScene = dynamic_cast<PacmanScene*>(pScene);


}

Pacman::~Pacman()
{

}

void Pacman::Update(float elapsedSec)
{
	m_EnemyPositions = m_CurrScene->GetEnemyPositions();

	Actor::Update(elapsedSec);
}

void Pacman::Render() const
{
	Actor::Render();
}

void dae::Pacman::Init()
{
	AddComponent(new SpriteComponent("pacman_move_anim.png", 50.0f, 50.0f, 5, 10));
	GetTransform()->SetPosition(256.0f, 256.0f, 0.0f);
}
