#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SDL2/SDL.h>
#include <string>

class GameObject
{
    static int s_ID;
    int m_ID;
public:
    GameObject()
    {
        SetID(s_ID);
    }
    int GetID() { return m_ID; }
    void Load(int x, int y, int width, int height, std::string textureID);
    void Update();
    void Render(SDL_Renderer* pRenderer);
    void Clean();
private:
    void SetID(int ID) { s_ID++; m_ID = s_ID; }
protected:
    std::string m_textureID;

    int m_currentFrame;
    int m_currentRow;

    int m_x;
    int m_y;

    int m_width;
    int m_height;
};

#endif