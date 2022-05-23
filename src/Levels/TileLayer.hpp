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
#include <Layer.hpp>
#include <Level.hpp>
#include <Vector2D.hpp>
#include <vector>

struct Tileset;

class TileLayer : public Layer
{
public:
    TileLayer(int tileSize, int mapWidth, int mapHeight, const std::vector<Tileset> &tilesets);

    virtual void Update();
    virtual void Render();
    int GetMapWidth() { return m_mapWidth; }
    int GetMapHeight() { return m_mapHeight; }

    void SetMapWidth(int mapWidth) { m_mapWidth = mapWidth; }
    void SetMapHeight(int mapHeight) { m_mapHeight = mapHeight; }
    void setTileIDs(const std::vector<std::vector<int> > &data) { m_tileIDs = data; }
    std::vector<std::vector<int> > GetTileIDs() { return m_tileIDs; }
    Vector2D GetPosition() { return m_position; }
    int GetTileSize() { return m_tileSize; }
    Tileset GetTilesetByID(int ID);
private:
    int m_numColumns;
    int m_numRows;
    int m_tileSize;

    int m_mapWidth;
    int m_mapHeight;

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