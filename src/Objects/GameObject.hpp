#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SDL2/SDL.h>
#include <string>
#include <LoaderParams.hpp>
#include <vector>

class TileLayer;

class GameObject
{
public:
    virtual ~GameObject() {}
    virtual void Update()=0;
    virtual void Draw()=0;
    virtual void Clean()=0;
    virtual void Collision()=0;
    virtual std::string GetTye()=0;
    void SetCollisionLayer(std::vector<TileLayer*>* collisionLayers) { m_collisionLayer = collisionLayers; }

    virtual void Load(const LoaderParams* pParams)=0;
protected:
    GameObject() {}
    std::vector<TileLayer*>* m_collisionLayer;
};

#endif