#include "MiniginPCH.h"
#include "Pacman.h"
#include "../Components/SpriteComponent.h"
using namespace dae;

Pacman::Pacman(Scene & scene):
	Actor(scene, false)
{
	

}

Pacman::~Pacman()
{

}

void Pacman::Update(float elapsedSec)
{
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
