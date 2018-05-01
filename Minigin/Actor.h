#pragma once
#include "GameObject.h"

enum Direc
{
	up = 0,
	down = 1,
	left = 2,
	right =3

};
class Actor: public dae::GameObject
{
public:
	Actor();
	~Actor();

	void Update(float elapsedSec);
	void SetDirection(const Direc direction);

private:
	Direc m_Direction;
	float m_Speed;

};

