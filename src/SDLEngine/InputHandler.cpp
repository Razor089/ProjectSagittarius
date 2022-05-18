#include <InputHandler.hpp>
#include <SDLEngine.hpp>

InputHandler* InputHandler::pInstance = 0;

InputHandler* InputHandler::Instance()
{
    if(pInstance == 0) pInstance = new InputHandler();
    return pInstance;
}

void InputHandler::Update()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                Engine::Instance()->IsRunning = false;
                break;
            case SDL_KEYDOWN:
                OnKeyDown();
                break;
            case SDL_KEYUP:
                OnKeyUp();
                break;
            default:
                break;
        }
    }
}

void InputHandler::OnKeyDown()
{
    m_Keyscan = SDL_GetKeyboardState(0);
}

void InputHandler::OnKeyUp()
{
    m_Keyscan = SDL_GetKeyboardState(0);
}

bool InputHandler::IsKeyDown(SDL_Scancode key) const
{
    if(m_Keyscan != 0)
    {
        if(m_Keyscan[key] == 1) return true;
    }
    return false;
}