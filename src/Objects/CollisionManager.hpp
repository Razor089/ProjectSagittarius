#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H
#include <GameObject.hpp>
#include <Player.hpp>
#include <TileLayer.hpp>

class CollisionManager
{
public:
    void CheckPlayerTileCollision(Player* pPlayer, const std::vector<TileLayer*> &collisionLayers);
    static CollisionManager* Instance();
private:
    CollisionManager(){}

    static CollisionManager* m_instance;
};

#endif