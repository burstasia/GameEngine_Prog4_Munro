#include "MiniginPCH.h"
#include "Renderer.h"
#include <SDL.h>
#include "SceneManager.h"
#include "Texture2D.h"

void dae::Renderer::Init(SDL_Window * window)
{
	mRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (mRenderer == nullptr) {
		std::stringstream ss; ss << "SDL_CreateRenderer Error: " << SDL_GetError();
		throw std::runtime_error(ss.str().c_str());
	}
}

void dae::Renderer::Render()
{
	SDL_RenderClear(mRenderer);

	SceneManager::GetInstance().Render();
	
	SDL_RenderPresent(mRenderer);
}

void dae::Renderer::Destroy()
{
	if (mRenderer != nullptr)
	{
		SDL_DestroyRenderer(mRenderer);
		mRenderer = nullptr;
	}
}

void dae::Renderer::RenderTexture(SDL_Texture& texture, const float x, const float y) const
{
	SDL_Rect dst;
	dst.x = static_cast<int>(x);
	dst.y = static_cast<int>(y);
	SDL_QueryTexture(&texture, nullptr, nullptr, &dst.w, &dst.h);
	SDL_RenderCopy(GetSDLRenderer(), &texture, nullptr, &dst);
}

void dae::Renderer::RenderTexture(SDL_Texture& texture, const float x, const float y, const float width, const float height) const
{
	SDL_Rect dst;
	dst.x = static_cast<int>(x);
	dst.y = static_cast<int>(y);
	dst.w = static_cast<int>(width);
	dst.h = static_cast<int>(height);
	SDL_RenderCopy(GetSDLRenderer(), &texture, nullptr, &dst);
}

void dae::Renderer::RenderTexture(SDL_Texture& texture, float x, float y, int width, int height, float srcX, float srcY, int srcWidth, int srcHeight) const
{
	UNREFERENCED_PARAMETER(width);
	UNREFERENCED_PARAMETER(height);

	SDL_Rect dst;
	dst.x = static_cast<int>(x);
	dst.y = static_cast<int>(y);
	dst.w = static_cast<int>(32);
	dst.h = static_cast<int>(32);

	SDL_Rect src;
	src.x = static_cast<int>(srcX);
	src.y = static_cast<int>(srcY);
	src.w = static_cast<int>(srcWidth);
	src.h = static_cast<int>(srcHeight);


	SDL_Point center;
	center.x = int(dst.w / 2.0f);
	center.y = int(dst.h / 2.0f);

	SDL_RenderCopyEx(GetSDLRenderer(), &texture, &src, &dst, 0, &center, SDL_FLIP_NONE);


}
