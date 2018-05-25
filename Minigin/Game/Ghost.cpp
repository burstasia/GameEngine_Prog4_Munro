#include "MiniginPCH.h"
#include "Ghost.h"
#include "../Components/SpriteComponent.h"

using namespace dae;

Ghost::Ghost(Scene* pScene):
	Actor(pScene, true)
{
}


Ghost::~Ghost()
{
}

void Ghost::Update(float elapsedSec)
{
	Actor::Update(elapsedSec);
}

void Ghost::Render() const
{
	Actor::Render();
}

void Ghost::Init(const std::string& fileName)
{
	AddComponent(new SpriteComponent(fileName,256.0f, 256.0f, 2, 10));
	GetTransform()->SetPosition(256.0f, 256.0f, 0.0f);
}
