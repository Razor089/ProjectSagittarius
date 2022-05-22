#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H
#include <GameObject.hpp>
#include <Player.hpp>
#include <TileLayer.hpp>

class CollisionManager
{
public:
   
    static CollisionManager* Instance();
private:
    CollisionManager(){}

    static CollisionManager* m_instance;
};

#endif