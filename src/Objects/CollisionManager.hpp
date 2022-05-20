#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H
#include <GameObject.hpp>
#include <Player.hpp>
#include <TileLayer.hpp>

class CollisionManager
{
public:
    void CheckPlayerTileCollision(Player* pPlayer, const std::vector<TileLayer*> &collisionLayers);
};

#endif