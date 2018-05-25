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
#include "./Objects/GameObject.h"
#include "TextObject.h"
#include "./Components/TextureComponent.h"
#include "./Components/TextComponent.h"
#include "./Components/SpriteComponent.h"
#include "./Components/TransformComponent.h"
#include "LevelLoader.h"

//GAME
#include "./Game/Pacman.h"

const int msPerFrame = 16; //16 for 60 fps, 33 for 30 fps
auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");

auto theRealG = std::make_shared<dae::Pacman>(scene);

auto gPacman = std::make_shared<dae::Actor>(scene, false);
auto gGhost_01 = std::make_shared<dae::Actor>(scene, true);
auto gGhost_02 = std::make_shared<dae::Actor>(scene, true);
auto gGhost_03 = std::make_shared<dae::Actor>(scene, true);
//auto gLevelLoader = new dae::LevelLoader();

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

		scene.LoadLevel("../Data/level/level.json");

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

			if (command) command->Execute(theRealG);

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
		512,                    
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
	
	
	//auto go = std::make_shared<dae::GameObject>();
	//go->AddComponent(new dae::TextureComponent("background.jpg", 0.0f, 0.0f));
	//scene.Add(go);

	////go = std::make_shared<dae::GameObject>();
	//go->AddComponent(new dae::TextComponent("fuck me", "Lingua.otf", 36, 0.0f, 0.0f));
	//scene.Add(go);

	
	//gPacman->AddComponent(new dae::SpriteComponent("pacman_move_anim.png", 50.0f, 50.0f, 5, 10));
	//scene.Add(gPacman);

	//gPacman->GetTransform()->SetPosition(256.0f, 256.0f, 0.0f);

	theRealG->Init();
	scene.Add(theRealG);

	gGhost_01->AddComponent(new dae::SpriteComponent("ghost_01.png", 256.0f, 256.0f, 2, 10));
	gGhost_01->GetTransform()->SetPosition(256.0f, 256.0f, 0.0f);
	scene.Add(gGhost_01);
	gGhost_02->AddComponent(new dae::SpriteComponent("ghost_02.png", 256.0f, 256.0f, 2, 10));
	gGhost_02->GetTransform()->SetPosition(256.0f, 256.0f, 0.0f);
	scene.Add(gGhost_02);
	gGhost_03->AddComponent(new dae::SpriteComponent("ghost_03.png", 256.0f, 256.0f, 2, 10));
	gGhost_03->GetTransform()->SetPosition(256.0f, 256.0f, 0.0f);
	scene.Add(gGhost_03);
	//gLevelLoader->LoadLevel("../Data/level/level.json");

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

