#pragma once
#include "./Scene.h"
#include "./Game/Pacman.h"
#include "./Game/Ghost.h"
namespace dae
{
	class PacmanScene final : public Scene
	{
	public:
		PacmanScene();
		~PacmanScene();

		void Update(float elapsedSec) override;
		void Render() const;
		void Init();
		std::vector<float2>& GetEnemyPositions();
	private:
		std::shared_ptr<Pacman> m_pPacman;

		std::shared_ptr<Ghost> m_pGhost_01;
		std::shared_ptr<Ghost> m_pGhost_02;
		std::shared_ptr<Ghost> m_pGhost_03;

		std::vector<float2> m_GhostPositions;
	};
}


