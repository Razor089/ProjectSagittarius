#include "CollisionManager.hpp"

CollisionManager* CollisionManager::m_instance = 0;

void CollisionManager::CheckPlayerTileCollision(Player* pPlayer, const std::vector<TileLayer*> &collisionLayers)
{
    for(std::vector<TileLayer*>::const_iterator it = collisionLayers.begin(); it != collisionLayers.end(); ++it)
    {
        TileLayer* pTileLayer = (*it);

        std::vector<std::vector<int> > tiles = pTileLayer->GetTileIDs();

        Vector2D layerPos = pTileLayer->GetPosition();

        int x, y, tileColumn, tileRow, tileid = 0;

        // calculate position on tile map
        x = layerPos.GetX() / pTileLayer->GetTileSize();
        y = layerPos.GetY() / pTileLayer->GetTileSize();

        // if moving forwad or upwards
        if(pPlayer->GetVelocity().GetY() >= 0 || pPlayer->GetVelocity().GetX() >= 0)
        {
            tileColumn = (pPlayer->GetPosition().GetX() + pPlayer->GetWidth()) / pTileLayer->GetTileSize();
            tileRow = (pPlayer->GetPosition().GetY() + pPlayer->GetHeight()) / pTileLayer->GetTileSize();
            tileid = tiles[tileRow + y][tileColumn + x];
        }
        else if(pPlayer->GetVelocity().GetY() < 0 || pPlayer->GetVelocity().GetX() < 0)
        {
            tileColumn = pPlayer->GetPosition().GetX() / pTileLayer->GetTileSize();
            tileRow = pPlayer->GetPosition().GetY() / pTileLayer->GetTileSize();
            tileid = tiles[tileRow + y][tileColumn + x];
        }
        if(tileid != 0) // if the tileid is not blank then collide
        {
            pPlayer->Collision();
        }
    }
}

CollisionManager* CollisionManager::Instance()
{
    if(m_instance == 0) m_instance = new CollisionManager();
    return m_instance;
}