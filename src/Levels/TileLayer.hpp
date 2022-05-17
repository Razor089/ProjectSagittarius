/**
 * @file TileLayer.hpp
 * @author Cosimo Davide Viggiano (cosimod089@gmail.com)
 * @brief Class to store only the tileset
 * @version 0.1
 * @date 2022-05-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef TILELAYER_H
#define TILELAYER_H
#include "Layer.hpp"
#include "Level.hpp"
#include "../Vector2D.hpp"
#include <vector>

class TileLayer : public Layer
{
public:
    TileLayer(int tileSize, int mapWidth, int mapHeight, const std::vector<Tileset> &tilesets);

    virtual void Update();
    virtual void Render();
    int GetMapWidth() { return m_mapWidth; }


    void SetMapWidth(int mapWidth) { m_mapWidth = mapWidth; }
    void setTileIDs(const std::vector<std::vector<int> > &data) { m_tileIDs = data; }
    Tileset GetTilesetByID(int ID);
private:
    int m_numColumns;
    int m_numRows;
    int m_tileSize;

    int m_mapWidth;

    /**
     * @brief Vector position to store 
     * the position of the map.
     * Used also when we scroll the map
     */
    Vector2D m_position;
    Vector2D m_velocity;

    const std::vector<Tileset> &m_tilesets;
    std::vector<std::vector<int> > m_tileIDs;
};

#endif