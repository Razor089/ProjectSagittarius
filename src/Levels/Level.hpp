#ifndef LEVEL_H
#define LEVEL_H
#include <string>
#include <vector>
#include <Layer.hpp>
#include <LevelParser.hpp>
#include <Player.hpp>


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

    /**
     * @brief Get the Collision Layers object
     * 
     * @return std::vector<Layer*>* 
     */
    std::vector<Layer*>* GetCollisionLayers() { return &m_collisionLayers; }

    /**
     * @brief Set the Player object
     * 
     * @param player the Player object
     */
    void SetPlayer(Player* player) { m_player = player; }

    /**
     * @brief Get the Player object
     * 
     * @return Player* - The pointer to the Player object
     */
    Player* GetPlayer() { return m_player; }
private:
    friend class LevelParser;
    Level() {}
    std::vector<Tileset> m_tilesets;
    std::vector<Layer*> m_layers;
    std::vector<Layer*> m_collisionLayers;
    Player* m_player;
};

#endif