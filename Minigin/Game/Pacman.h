#pragma once
#include "../Objects/Actor.h"
#include "../Scene.h"



namespace dae
{
	class PacmanScene;

	struct int2
	{
		int2(int x, int y) : x(x), y(y) {}
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

		void IncreaseScore(int amount);
		int GetScore() const;
		int GetLives() const;

		bool GetDead();
	private:
		
		std::vector<int2> m_EnemyPositions;

		int2 m_StartPos;
		PacmanScene* m_CurrScene;
		bool m_IsHit;
		int m_Lives;
		int m_Score;

		bool m_IsDead;
		//HELPER FUNCTIONS
		void CheckCollisionEnemies();
		void ResetPacman();
		void Death();

	};
}


