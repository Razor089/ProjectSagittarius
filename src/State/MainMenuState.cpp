#include <MainMenuState.hpp>
#include <InputHandler.hpp>
#include <SDLEngine.hpp>
#include <TextureLoader.hpp>
#include <Levels/LevelParser.hpp>
#include <Camera.hpp>
#include <SDL2/SDL.h>
#include <iostream>

void MainMenuState::Enter(StateMachine* sm)
{
    std::cout << "Entering MainMenuState" << std::endl;
    wid = 500;
    heig = 500;
    pos = 0;
    //if(!(TextureLoader::Instance()->LoadTexture("C:/Users/Davide/Desktop/C++/SDL_Template/bin/res/Dune.png", "Wallpaper"))) std::cout << "Error loading image!" << std::endl;
    LevelParser* parser = new LevelParser();
    level = parser->ParseLevel("res/Ufficio.tmx");
    std::cout << "Level tilset size: " << level->GetTilesets()->size() << std::endl;
    std::cout << "Level layers size: " << level->GetLayers()->size() << std::endl;
}

void MainMenuState::Update(StateMachine* sm)
{
    if(InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_ESCAPE)) Engine::Instance()->IsRunning = false;

    level->Update();
}

void MainMenuState::Render(StateMachine* sm)
{
    level->Render();
}

void MainMenuState::Exit(StateMachine* sm)
{
    std::cout << "Exiting MainMenuState" << std::endl;
}