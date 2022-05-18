#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SDL2/SDL.h>
#include <string>
#include <LoaderParams.hpp>

class GameObject
{
public:
    virtual void Update()=0;
    virtual void Draw()=0;
    virtual void Clean()=0;

    virtual void Load(const LoaderParams* pParams)=0;
protected:
    GameObject() {}
};

#endif