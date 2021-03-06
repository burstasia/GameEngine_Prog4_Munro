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
#include "./PacmanScene.h"

//GAME
#include "./Game/Pacman.h"
#include "./Game/Ghost.h"

const int msPerFrame = 16; //16 for 60 fps, 33 for 30 fps
//auto scene = std::make_shared<Scene>("demo");
//dae::SceneManager::GetInstance().AddScene(std::make_shared<dae::PacmanScene>());

//auto theRealG = std::make_shared<dae::Pacman>(scene);
//auto ghost = std::make_shared<dae::Ghost>(scene);


void Initialize();
void LoadGame();
void Cleanup();

#pragma warning( push )  
#pragma warning( disable : 4100 )  
int main(int argc, char* argv[]) {
#pragma warning( pop )
	_CrtSetBreakAlloc(6056);

	srand((unsigned int)time(NULL));
	Initialize();

	// tell the resource manager where he can find the game data
	dae::ResourceManager::GetInstance().Init("../Data/");

	LoadGame();

	{

		auto lastTime = std::chrono::high_resolution_clock::now();
		auto& renderer = dae::Renderer::GetInstance();
		auto& sceneManager = dae::SceneManager::GetInstance();
		auto& input = dae::InputManager::GetInstance();

		sceneManager.AddScene(std::make_shared<dae::PacmanScene>());

		//scene.LoadLevel("../Data/level/level.json");
		sceneManager.Init();

		bool doContinue = true;
		while(doContinue) 
		{
			//why do I update and render at the same time?
			//I am not worried about latency between players in the game
			// this will be a single player game 

			auto currentTime = std::chrono::high_resolution_clock::now();
			auto elapsedSeconds = std::chrono::duration<float>(currentTime - lastTime).count();

			doContinue = input.ProcessInput();

			/*auto command = input.HandleInput();

			if (command) command->Execute(theRealG);*/

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
		"Nicole Munro - Minigin",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,                    
		512,
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
	
	
	/*theRealG->Init();
	scene.Add(theRealG);

	ghost->Init("ghost_01.png");
	scene.Add(ghost);*/
}

void Cleanup()
{
	dae::Renderer::GetInstance().Destroy();
	SDL_DestroyWindow(window);
	SDL_Quit();

}

