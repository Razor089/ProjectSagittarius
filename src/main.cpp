#include <iostream>
#include <SDLEngine.hpp>
#include <InputHandler.hpp>
#include <SDL2/SDL.h>

#define FPS 60
#define DELAY_TIME 1000/FPS

int main(int argc, char** argv)
{

    Uint32 frameStart, frameTime;

    if(Engine::Instance()->Init() == false)
    {
        std::cout << "Cannot initialize SDLEngine" << std::endl;
        return -1;
    }

    while(Engine::Instance()->IsRunning)
    {

        frameStart = SDL_GetTicks();

        Engine::Instance()->HandleInputs();
        Engine::Instance()->Run();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameTime < DELAY_TIME)
        {
            SDL_Delay((int)(DELAY_TIME - frameTime));
        }
    }

    Engine::Instance()->Close();
    return 0;
}