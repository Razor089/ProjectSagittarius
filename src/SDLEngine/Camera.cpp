#include "Camera.hpp"
#include "SDLEngine.hpp"

Camera* Camera::instance = 0;

Camera* Camera::GetInstance()
{
    if(instance == 0) instance = new Camera();
    return instance;
}

const Vector2D Camera::GetPosition() const
{

    if(m_targetPos != 0)
    {
        Vector2D pos(m_targetPos->GetX() - WIDTH/2, 0);
        if(pos.GetX() < 0)
        {
            pos.SetX(0);
        }
        return pos;
    }
    return m_position;
}

void Camera::Update(Vector2D velocity)
{
    m_position += velocity;
    if(m_position.m_x < 0) m_position.m_x = 0;
}