#ifndef SDLGAMEOBJECT_H
#define SDLGAMEOBJECT_H
#include <GameObject.hpp>
#include <LoaderParams.hpp>
#include <string>
#include <Vector2D.hpp>

class SDLGameObject : public GameObject
{
public: 
    SDLGameObject();

    virtual void Draw();
    virtual void Update();
    virtual void Clean();

    virtual void Load(const LoaderParams* pParams);
protected:

    int m_width;
    int m_height;

    int currentRow;
    int currentFrame;

    Vector2D m_position;
    Vector2D m_velocity;
    Vector2D m_acceleration;

    int m_numFrames;

    std::string textureID;
};

#endif