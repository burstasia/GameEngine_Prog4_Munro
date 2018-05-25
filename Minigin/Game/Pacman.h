#pragma once
#include "../Objects/Actor.h"
#include "../Scene.h"

namespace dae
{
	class Pacman final : public Actor
	{
	public:
		Pacman(Scene & scene);
		~Pacman();

		void Update(float elapsedSec);
		void Render() const;
		void Init();
	private:
		
	};
}


