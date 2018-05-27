#pragma once
#include "../Objects/GameObject.h"
#include "../Scene.h"
namespace dae
{
	class HUD final: public GameObject 
	{
	public:
		HUD(Scene* pScene);
		~HUD();

		void Update(float elapsedSec);
		void Render() const;
		void Init();

		void IncreaseScore(int score);
		void SetLives(int lives);


	private:
		int m_Lives;
		int m_Score;
	};
}


