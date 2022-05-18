#ifndef CAMERA_H
#define CAMERA_H
#include "Vector2D.hpp"

class Camera
{
public:
    static Camera* GetInstance();
    const Vector2D GetPosition() const;
    void Update(Vector2D velocity);
private:
    static Camera* instance;
    Camera() : m_targetPos(0), m_position(0,0)
    {}

    // Camera's position
    Vector2D m_position;

    // Target's position
    Vector2D* m_targetPos;
};
typedef Camera TheCamera;

#endif