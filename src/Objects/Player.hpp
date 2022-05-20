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
    Vector2D GetVelocity() { return m_velocity; }
    Vector2D GetPosition() { return m_position; }
    int GetWidth() { return m_width; }
    int GetHeight() { return m_height; }
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