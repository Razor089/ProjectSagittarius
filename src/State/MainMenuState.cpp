#include <MainMenuState.hpp>
#include <InputHandler.hpp>
#include <SDLEngine.hpp>
#include <TextureLoader.hpp>
#include <LevelParser.hpp>
#include <Camera.hpp>
#include <SDL2/SDL.h>
#include <iostream>
#include <Player.hpp>
#include <CollisionManager.hpp>

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
    //TextureLoader::Instance()->DrawFrame("Player", WIDTH/2, HEIGHT/2, 32, 32, 0, 1, Engine::Instance()->GetRenderer());
    /*
    SDL_Texture* texture = TextureLoader::Instance()->GetTexture("Player");
    int w, h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    SDL_Rect srcRect;
    SDL_Rect dstRect;

    srcRect.x = 3 * 32; // numFrames * tileWidth
    srcRect.y = 0 * 64; // numRows * tileHeight
    srcRect.w = dstRect.w = 32;
    srcRect.h = dstRect.h = 64;
    dstRect.x = WIDTH/2;
    dstRect.y = HEIGHT/2;

    SDL_RenderCopyEx(Engine::Instance()->GetRenderer(), texture, &srcRect, &dstRect, 0, 0, SDL_FLIP_NONE);
    */
}

void MainMenuState::Exit(StateMachine* sm)
{
    std::cout << "Exiting MainMenuState" << std::endl;
}