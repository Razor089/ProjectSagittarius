#ifndef PLAYER_H
#define PLAYER_H
#include <SDLGameObject.hpp>
#include <BaseCreator.hpp>

class GameObject;

class Player : public SDLGameObject
{
public:
    Player();
    void Draw();
    void Update();
    void Clean();
    void Load(const LoaderParams* pParams);
    virtual void Collision();

    virtual std::string GetType() { return "Player"; }
private:
    bool m_up, m_down, m_left, m_right;
    int last_direction;
    void HandleInputs();
    void Move();
};

class PlayerCreator : public BaseCreator
{
    GameObject* CreateGameObject() const
    {
        return new Player();
    }
};

#endif