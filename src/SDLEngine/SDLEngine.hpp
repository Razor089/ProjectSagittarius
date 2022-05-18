#ifndef SDLENGINE_H
#define SDLENGINE_H
#include <SDL2/SDL.h>
#include <stdlib.h>

#define WIDTH 1024
#define HEIGHT 768

class SDLEngine
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    static SDLEngine* pInstance;
public:
    static SDLEngine* Instance();
    bool Init();
    void Run();
    void HandleInputs();
    void Close();
    bool IsRunning;
    SDL_Renderer* GetRenderer() { return renderer; }
private:
    SDLEngine() : window(NULL),
                  renderer(NULL),
                  IsRunning(true)
    {}
};
typedef SDLEngine Engine;

#endif