#include <LevelParser.hpp>
#include <TileLayer.hpp>
#include <TextureLoader.hpp>
#include <base64.h>
#include <ObjectLayer.hpp>
#include <GameObjectFactory.hpp>
#ifdef __WIN32__
#include <Zlib/zlib.h>
#elif __APPLE__
#include <zlib.h>
#endif

Level* LevelParser::ParseLevel(const char* levelFile)
{
    //Create a TinyXML document and load the map XML
    std::cout << "Parsing: " << levelFile << std::endl;
    TiXmlDocument levelDocument;
    if(!levelDocument.LoadFile(levelFile))
    {
        std::cout << "Error loading: " << levelFile << std::endl;
    }

    // Create the level object
    Level* pLevel = new Level();

    // Get the root node
    TiXmlElement* pRoot = levelDocument.RootElement();

    pRoot->Attribute("tilewidth", &m_tileSize);
    pRoot->Attribute("width", &m_width);
    pRoot->Attribute("height", &m_height);

    // We know that properties is the first child of the root
    TiXmlElement* pProperties = pRoot->FirstChildElement();

    for(TiXmlElement* e = pProperties->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
    {
        if(e->Value() == std::string("property"))
        {
            ParseTextures(e);
        }
    }

    // Parse the tilesets
    for(TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
    {
        if(e->Value() == std::string("tileset"))
        {
            std::cout << "Parsing: " << e->Attribute("name") << std::endl;
            ParseTileSets(e, pLevel->GetTilesets());
        }
    }

    // Parse any object layers
    for(TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
    {
        if(e->Value() == std::string("layer") || e->Value() == std::string("objectgroup"))
        {
            if(e->FirstChildElement()->Value() == std::string("object"))
            {
                ParseObjectLayer(e, pLevel, pLevel->GetLayers());
            }
            else if(e->FirstChildElement()->Value() == std::string("data") || 
                e->FirstChildElement()->NextSiblingElement() != 0 && e->FirstChildElement()->NextSiblingElement()->Value() == std::string("data"))
            {
                std::cout << "Parsing Layer:" << e->Attribute("name") << std::endl;
                ParseTileLayer(e, pLevel->GetLayers(), pLevel->GetTilesets(), pLevel->GetCollisionLayers());
            }
        }
    }

    return pLevel;
}

void LevelParser::ParseTileSets(TiXmlElement* pTilesetRoot, std::vector<Tileset>* pTileset)
{
    // Add the tileset texture to the texture loader
    
    std::string fName = std::string(pTilesetRoot->FirstChildElement()->Attribute("source"));
    TextureLoader::Instance()->LoadTexture(("res/" + fName).c_str(), pTilesetRoot->Attribute("name"));

    // Create tileset object
    Tileset tileset;
    tileset.margin = 0;
    tileset.spacing = 0;
    pTilesetRoot->FirstChildElement()->Attribute("width", &tileset.width);
    pTilesetRoot->FirstChildElement()->Attribute("height", &tileset.height);
    pTilesetRoot->Attribute("firstgid", &tileset.firstGridID);
    pTilesetRoot->Attribute("tilewidth", &tileset.tileWidth);
    pTilesetRoot->Attribute("tileheight", &tileset.tileHeight);
    pTilesetRoot->Attribute("spacing", &tileset.spacing);
    pTilesetRoot->Attribute("margin", &tileset.margin);
    tileset.name = pTilesetRoot->Attribute("name");

    tileset.numColumns = tileset.width / (tileset.tileWidth + tileset.spacing);

    /*
    std::cout << "------Tileset Loaded------" << std::endl;
    std::cout << "Tileset Name: " << tileset.name << std::endl;
    std::cout << "Tileset Width: " << tileset.width << std::endl;
    std::cout << "Tileset firstgid: " << tileset.firstGridID << std::endl;
    std::cout << "Tileset tilewidth: " << tileset.tileWidth << std::endl;
    std::cout << "Tileset tileheight: " << tileset.tileHeight << std::endl;
    std::cout << "Tileset spacing: " << tileset.spacing << std::endl;
    std::cout << "Tileset margin: " << tileset.margin << std::endl;
    std::cout << "Tileset numColumns: " << tileset.numColumns << std::endl;
    */

    pTileset->push_back(tileset);
}

void LevelParser::ParseTileLayer(TiXmlElement* pTileElement, std::vector<Layer*>* player, std::vector<Tileset>* pTilesets, std::vector<TileLayer*>* pCollisionLayer)
{
    TileLayer* pTileLayer = new TileLayer(m_tileSize, m_width, m_height, *pTilesets);

    std::vector<std::vector<int> > data;
    bool collider = false;

    std::string decodedIDs;
    TiXmlElement* pDataNode;

    for(TiXmlElement* e = pTileElement->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
    {
        std::cout << "e->Value(): " << e->Value() << std::endl;
        if(e->Value() == std::string("properties"))
        {
            for(TiXmlElement* property = e->FirstChildElement(); property != NULL; property = property->NextSiblingElement())
            {
                if(property->Value() == std::string("property"))
                {
                    if(property->Attribute("name") == std::string("collider"))
                    {
                        std::cout << "Collider true" << std::endl;
                        collider = true;
                    }
                }
            }
        }

        if(e->Value() == std::string("data"))
        {
            std::cout << "Assigning data" << std::endl;
            pDataNode = e;
        }
    }

    for(TiXmlNode* e = pDataNode->FirstChild(); e != NULL; e = e->NextSibling())
    {
        TiXmlText* text = e->ToText();
        std::string t = text->Value();
        //std::cout << "Decoding: " << t << std::endl;
        decodedIDs = base64_decode(t);

        uLongf numGids = m_width * m_height * sizeof(int);
        std::vector<unsigned> gids(numGids);
        uncompress((Bytef*)&gids[0], &numGids, (const Bytef*)decodedIDs.c_str(), decodedIDs.size());
        std::vector<int> layerRow(m_width);

        for(int j = 0; j < m_height; j++)
        {
            data.push_back(layerRow);
        }

        for(int rows = 0; rows < m_height; rows++)
        {
            for(int cols = 0; cols < m_width; cols++)
            {
                data[rows][cols] = gids[rows * m_width + cols];
            }
        }

        pTileLayer->setTileIDs(data);

        if(collider)
        {
            pCollisionLayer->push_back(pTileLayer);
        }

        player->push_back(pTileLayer);
    }
}

void LevelParser::ParseTextures(TiXmlElement* pTextureRoot)
{
    std::cout << "adding texture " << pTextureRoot->Attribute("value") << " with ID " << pTextureRoot->Attribute("name") << std::endl;
    std::string fName = pTextureRoot->Attribute("value");
    TextureLoader::Instance()->LoadTexture(("res/" + fName).c_str(), pTextureRoot->Attribute("name"));
}

void LevelParser::ParseObjectLayer(TiXmlElement* pObjectElement, Level* pLevel, std::vector<Layer*>* pLayers)
{
    // Create an object layer
    ObjectLayer* pObjectLayer = new ObjectLayer();

    std::cout << "Object Layer name: " <<pObjectElement->FirstChildElement()->Attribute("name") << std::endl;

    for(TiXmlElement* e = pObjectElement->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
    {
        std::cout << "Parsing Object Layer type: " << e->Attribute("type") << std::endl;
        if(e->Value() == std::string("object"))
        {
            int x, y, width, height, numFrames, callbackID, animSpeed;
            std::string TextureID;

            // Get the initial node values type
            e->Attribute("x", &x);
            e->Attribute("y", &y);
            std::cout << "x: " << e->Attribute("x") << std::endl;
            std::cout << "y: " << e->Attribute("y") << std::endl;
            GameObject* pGameObject = GameObjectFactory::Instance()->create(e->Attribute("type"));
            std::cout << "Created :" << e->Attribute("type") << std::endl;
            for(TiXmlElement* properties = e->FirstChildElement(); properties != NULL; properties = properties->NextSiblingElement())
            {
                std::cout << "Properties Value: " << properties->Value() << std::endl;
                if(properties->Value() == std::string("properties"))
                {
                    for(TiXmlElement* property = properties->FirstChildElement(); property != NULL; property = property->NextSiblingElement())
                    {
                        std::cout << "Property Value: " << property->Value() << std::endl;
                        if(property->Value() == std::string("property"))
                        {
                            std::string name = property->Attribute("name");
                            std::cout << "Property Name: " << name << std::endl;
                            std::cout << "Property Value: " << property->Attribute("value") << std::endl;

                            if(name == std::string("NumFrames"))
                            {  
                                property->Attribute("value", &numFrames); 
                            }
                            else if(property->Attribute("name") == std::string("TextureHeight"))
                            {
                                std::cout << "1" << std::endl;
                                property->Attribute("value", &height);
                            }
                            else if(property->Attribute("name") == std::string("TextureID"))
                            {
                                std::cout << "2" << std::endl;
                                TextureID = property->Attribute("value");
                            }
                            else if(property->Attribute("name") == std::string("TextureWidth"))
                            {
                                std::cout << "3" << std::endl;
                                property->Attribute("value", &width);
                            }
                            else if(property->Attribute("name") == std::string("CallbackID"))
                            {
                                std::cout << "4" << std::endl;
                                property->Attribute("value", &callbackID);
                            }
                            else if(property->Attribute("name") == std::string("AnimSpeed"))
                            {
                                std::cout << "5" << std::endl;
                                property->Attribute("value", &animSpeed);
                            }
                        }
                    }
                }
            }
            std::cout << "Prima del Load " << std::endl;
            pGameObject->Load(new LoaderParams(x, y, width, height, numFrames, animSpeed,TextureID));
            pGameObject->SetCollisionLayer(pLevel->GetCollisionLayers());
            std::cout << "Load effettuato" << std::endl;
            if(e->Attribute("type") == "Player")
            {
                pLevel->SetPlayer(dynamic_cast<Player*>(pGameObject));
            }
            pObjectLayer->GetGameObjects()->push_back(pGameObject);
            std::cout << "GameObject Inserito: " << pObjectLayer->GetGameObjects()->size() << std::endl;
        }
    }
    pLayers->push_back(pObjectLayer);
    std::cout << "ObjectLayer inserito " << std::endl;
}