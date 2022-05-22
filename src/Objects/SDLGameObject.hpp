#ifndef SDLGAMEOBJECT_H
#define SDLGAMEOBJECT_H
#include <GameObject.hpp>
#include <LoaderParams.hpp>
#include <string>
#include <Vector2D.hpp>

class SDLGameObject : public GameObject
{
public: 
    virtual ~SDLGameObject(){}

    virtual void Draw();
    virtual void Update();
    virtual void Clean();
    virtual void Collision();
    virtual std::string GetTye();

    virtual void Load(const LoaderParams* pParams);
protected:
    SDLGameObject();
    bool CheckCollideTile(Vector2D newPos);
};

#endif