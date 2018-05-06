#pragma once
#include "Singleton.h"

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Texture;
namespace dae
{
	class Texture2D;
	class Renderer final : public Singleton<Renderer>
	{
		SDL_Renderer* mRenderer = nullptr;

	public:
		void Init(SDL_Window* window);
		void Render();
		void Destroy();

		void RenderTexture(SDL_Texture& texture, float x, float y) const;
		void RenderTexture(SDL_Texture& texture, float x, float y, float width, float height) const;
		void RenderTexture(SDL_Texture& texture, float x, float y, int width, int height, float srcX, float srcY, int srcWidth, int srcHeight) const;

		SDL_Renderer* GetSDLRenderer() const { return mRenderer; }
	};
}

