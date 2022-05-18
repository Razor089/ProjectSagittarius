#ifndef PLAYER_H
#define PLAYER_H
#include <SDLGameObject.hpp>
#include <BaseCreator.hpp>

class Player : public SDLGameObject
{
public:
    Player();
    void Draw();
    void Update();
    void Clean();
    void Load(const LoaderParams* pParams);
};

class PlayerCreator : public BaseCreator
{
    GameObject* CreateGameObject() const
    {
        return new Player();
    }
};

#endif