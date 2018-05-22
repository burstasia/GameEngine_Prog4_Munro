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
		Actor(const Scene& scene);
		~Actor();

		void Update(float elapsedSec) override;
		void SetDirection(const Direc direction);
		void SetSpeed(float speed);
		float GetSpeed();

	private:
		Direc m_Direction;
		float m_Speed;

		void NomralMovement(float elapsedSec);
		void EnemyMovement(float elapsedSec);
		void SetPosition(float elapsedSec);
	};
}


