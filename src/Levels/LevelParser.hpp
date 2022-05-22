#ifndef LEVELPARSER_H
#define LEVELPARSER_H
#include <Level.hpp>
#include <tinyxml.h>
#include <TileLayer.hpp>

class Level;
struct Tileset;
class Layer;
class TileLayer;

class LevelParser
{
public:
    LevelParser() {}
    Level* ParseLevel(const char* levelFile);    
private:
    void ParseTextures(TiXmlElement* pTextureRoot);
    void ParseObjectLayer(TiXmlElement* pObjectElement, Level* pLevel, std::vector<Layer*>* pLayers);
    void ParseTileSets(TiXmlElement* pTilesetRoot, std::vector<Tileset>* pTilesets);
    void ParseTileLayer(TiXmlElement* pTileElement, std::vector<Layer*> *pLayer, std::vector<Tileset>* pTilesets, std::vector<TileLayer*>* pCollisionLayer);

    int m_tileSize;
    int m_width;
    int m_height;
};

#endif