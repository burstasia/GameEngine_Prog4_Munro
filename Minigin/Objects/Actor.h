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
		Actor(const Scene& scene, bool isEnemy);
		~Actor();

		void Update(float elapsedSec) override;
		void SetDirection(const Direc direction);
		void SetSpeed(float speed);
		float GetSpeed();
		
	private:
		Direc m_Direction;
		float m_Speed;
		bool m_IsEnemy;

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


