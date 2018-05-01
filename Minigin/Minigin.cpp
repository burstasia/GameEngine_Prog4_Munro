#include "MiniginPCH.h"
// ReSharper disable once CppUnusedIncludeDirective
#include <vld.h>
#pragma comment(lib,"xinput.lib")
#include "SDL.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include <chrono>
#include <thread>
#include "InputManager.h"
#include "SceneManager.h"

#include "Scene.h"
#include "GameObject.h"
#include "TextObject.h"
#include "./Components/TextureComponent.h"
#include "./Components/TextComponent.h"

const int msPerFrame = 16; //16 for 60 fps, 33 for 30 fps
auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");

auto gGameActor = std::make_shared<Actor>();

void Initialize();
void LoadGame();
void Cleanup();

#pragma warning( push )  
#pragma warning( disable : 4100 )  
int main(int argc, char* argv[]) {
#pragma warning( pop )

	Initialize();

	// tell the resource manager where he can find the game data
	dae::ResourceManager::GetInstance().Init("../Data/");

	LoadGame();

	{

		auto lastTime = std::chrono::high_resolution_clock::now();
		auto& renderer = dae::Renderer::GetInstance();
		auto& sceneManager = dae::SceneManager::GetInstance();
		auto& input = dae::InputManager::GetInstance();

		bool doContinue = true;
		while(doContinue) 
		{
			//why do I update and render at the same time?
			//I am not worried about latency between players in the game
			// this will be a single player game 

			auto currentTime = std::chrono::high_resolution_clock::now();
			auto elapsedSeconds = std::chrono::duration<float>(currentTime - lastTime).count();

			doContinue = input.ProcessInput();

			auto command = input.HandleInput();

			if (command) command->Execute(gGameActor);

			sceneManager.Update(elapsedSeconds);

			renderer.Render();

			lastTime = currentTime;
			
		}
	}

	Cleanup();
    return 0;
}

SDL_Window* window;

void Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::stringstream ss; ss << "SDL_Init Error: " << SDL_GetError();
		throw std::runtime_error(ss.str().c_str());
	}

	window = SDL_CreateWindow(
		"Programming 4 assignment",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,                    
		480,                    
		SDL_WINDOW_OPENGL       
	);
	if (window == nullptr) {
		std::stringstream ss; ss << "SDL_CreateWindow Error: " << SDL_GetError();
		throw std::runtime_error(ss.str().c_str());
	}

	dae::Renderer::GetInstance().Init(window);
}

void LoadGame()
{
	
	
	auto go = std::make_shared<dae::GameObject>();
	go->AddComponent(new dae::TextureComponent("background.jpg", 0.0f, 0.0f));
	scene.Add(go);

	//go = std::make_shared<dae::GameObject>();
	go->AddComponent(new dae::TextComponent("fuck me", "Lingua.otf", 36, 0.0f, 0.0f));
	scene.Add(go);

	
	gGameActor->AddComponent(new dae::TextComponent("pacman", "Lingua.otf", 20, 50.0f, 50.0f));
	scene.Add(gGameActor);

	/*auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto to = std::make_shared<dae::TextObject>("Programming 4 Assignment", font);
	to->SetPosition(80, 20);
	scene.Add(to);*/
}

void Cleanup()
{
	dae::Renderer::GetInstance().Destroy();
	SDL_DestroyWindow(window);
	SDL_Quit();
}

