#ifndef LEVEL_H
#define LEVEL_H
#include <string>
#include <vector>
#include "Layer.hpp"
#include "LevelParser.hpp"


struct Tileset
{
    int firstGridID;
    int tileWidth;
    int tileHeight;
    int spacing;
    int margin;
    int width;
    int height;
    int numColumns;
    std::string name;
};

class Level
{
public:
    void Update();
    void Render();

    /**
     * @brief Get the Tilesets vector
     * 
     * @return std::vector<Tileset>* 
     */
    std::vector<Tileset>* GetTilesets() { return &m_tilesets; }
    /**
     * @brief Get the Layers vector
     * 
     * @return std::vector<Layer*>* 
     */
    std::vector<Layer*>* GetLayers() { return &m_layers; }
private:
    friend class LevelParser;
    Level() {}
    std::vector<Tileset> m_tilesets;
    std::vector<Layer*> m_layers;
};

#endif