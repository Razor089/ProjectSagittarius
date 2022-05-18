#ifndef PLAYER_H
#define PLAYER_H
#include <GameObject.hpp>

class Player : public GameObject
{
public:
    void Load(int x, int y, int width, int height, std::string textureID);
    void Draw(SDL_Renderer* pRenderer);
    void Update();
    void Clean();
};

#endif