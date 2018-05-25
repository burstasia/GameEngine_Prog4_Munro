#pragma once
#include "../Objects/Actor.h"
#include "../Scene.h"
namespace dae
{
	class Ghost final: public Actor
	{
	public:
		Ghost(Scene* pScene);
		~Ghost();

		void Update(float elapsedSec);
		void Render() const;
		void Init(const std::string& fileName);


	};
}


