#pragma once
#include "../Objects/Actor.h"
#include "../Scene.h"



namespace dae
{
	class PacmanScene;

	struct float2
	{
		float2(int x, int y) : x(x), y(y) {}
		int x;
		int y;
	};
	class Pacman final : public Actor
	{
	public:
		Pacman(Scene* pScene);
		~Pacman();

		void Update(float elapsedSec);
		void Render() const;
		void Init();
	private:
		
		std::vector<float2> m_EnemyPositions;

		float2 m_StartPos;

		PacmanScene* m_CurrScene;
	};
}


