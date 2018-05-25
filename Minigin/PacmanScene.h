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

		void Update(float elapsedSec);
		void Render() const;
		void Init();

	private:
		std::shared_ptr<Pacman> m_pPacman;

		std::shared_ptr<Ghost> m_pGhost_01;
	};
}


