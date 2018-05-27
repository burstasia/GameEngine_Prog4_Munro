#pragma once
#include "BaseComponent.h"
struct SDL_Texture;

namespace dae
{
	class SpriteComponent final: public BaseComponent
	{
	public:
		explicit SpriteComponent(const std::string& file, float posX, float posY, int numFrames, int numFramesPerSec);
		~SpriteComponent();

		void SetPosition(float x, float y);
		void SetAnimation(const std::string& file, int numFrames);

		SpriteComponent(const SpriteComponent &) = delete;
		SpriteComponent(SpriteComponent &&) = delete;
		SpriteComponent & operator= (const SpriteComponent &) = delete;
		SpriteComponent & operator= (const SpriteComponent &&) = delete;

	protected:
		virtual void Init()override;
		virtual void Update(float elapsedSec)override;
		virtual void Render() override;


	private:
		SDL_Texture * m_Texture;
		float m_PosX;
		float m_PosY;

		float m_Timer = 0.0f;
		bool m_Animating = false;
		int m_FramesPerSec = 0;
		int m_NumFrames = 0;
		int m_WidthTexture = 0;
		int m_HeightTexture = 0;
		int m_WidthFrame = 0;
		int m_HeightFrame = 0;
		int m_CurrFrame = 0;
	};
}



