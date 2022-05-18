#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include <SDL2/SDL.h>

enum MouseButton
{
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};

class InputHandler
{
    static InputHandler* pInstance;
public:
    static InputHandler* Instance();
    void Update();
    bool IsKeyDown(SDL_Scancode key) const;
private:
    InputHandler() : m_Keyscan(0)
    {}

    void OnKeyDown();
    void OnKeyUp();

    //Keyboard key pressed/released
    const Uint8* m_Keyscan;
};

#endif