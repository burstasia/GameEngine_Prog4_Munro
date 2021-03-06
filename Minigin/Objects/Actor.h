#pragma once
#include "GameObject.h"

enum Direc
{
	up = 0,
	down = 1,
	left = 2,
	right =3

};
namespace dae
{
	class Scene;

	class Actor : public dae::GameObject
	{
	public:
		Actor(Scene* pScene, bool isEnemy);
		~Actor();

		void Update(float elapsedSec) override;
		void SetDirection(const Direc direction);
		void SetSpeed(float speed);
		float GetSpeed();
		int GetScore();
		bool GetInvincible();

		void SetDying(bool dying);

	private:
		Direc m_Direction;
		float m_CurrSpeed;
		float m_NormalSpeed;
		float m_SuperSpeed;
		bool m_IsEnemy;

		int m_Score;
		int m_PillScore;
		int m_SuperPillScore;
		bool m_IsInvincible;
		float m_TotalInvincibleTime;
		float m_CurrInvincibleTime;

		bool m_IsDying;

		//enemy variables
		float m_DistanceToTravel;
		float m_DistanceTravelled;
		bool m_IsReachedGoal;
		bool m_IsGoalSet;

		void NormalMovement(float elapsedSec);
		void EnemyMovement(float elapsedSec);
		void SetPosition(float elapsedSec, float speed);
		void SetDirectionEnemy();


	};
}


