#ifndef PLAYER_H
#define PLAYER_H
#include <GameObject.hpp>
#include <BaseCreator.hpp>

class Player : public GameObject
{
public:
    void Load(int x, int y, int width, int height, std::string textureID);
    void Draw(SDL_Renderer* pRenderer);
    void Update();
    void Clean();
};

class PlayerCreator : public BaseCreator
{
    GameObject* CreateGameObject() const
    {
        return new Player();
    }
};

#endif