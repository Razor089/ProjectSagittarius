#include <TileLayer.hpp>
#include <SDLEngine.hpp>
#include <TextureLoader.hpp>
#include <Camera.hpp>

void TileLayer::Update()
{
    m_position += m_velocity;
}

void TileLayer::Render()
{
    int x, y, x2, y2 = 0;

    x = m_position.GetX() / m_tileSize;
    y = m_position.GetY() / m_tileSize;

    x2 = int(m_position.GetX()) % m_tileSize;
    y2 = int(m_position.GetY()) % m_tileSize;

    for(int i = 0; i < m_numRows; i++)
    {
        for(int j = 0; j < m_numColumns; j++)
        {
            int id = m_tileIDs[i + y][j + x];
            //std::cout << "ID: " << id << std::endl;
            if(id == 0 )
            {
                continue;
            }

            if(((j * m_tileSize) - x2) - TheCamera::GetInstance()->GetPosition().m_x < -m_tileSize || ((j * m_tileSize) - TheCamera::GetInstance()->GetPosition().m_x > WIDTH))
            {
                continue;
            }

            Tileset tileset = GetTilesetByID(id);
            id--;

            // Draw function
            /*
            std::cout << "Current Row: " << tileset.numColumns << std::endl;
            std::cout << "CurrentFrame: " << (id - (tileset.firstGridID - 1)) % tileset.numColumns << std::endl;
        
            std::cout << "Trying to draw: " << tileset.name << std::endl;
            */
            TextureLoader::Instance()->DrawTile(tileset.name,  tileset.margin, tileset.spacing, ((j * m_tileSize) - x2) - TheCamera::GetInstance()->GetPosition().m_x, (i * m_tileSize) - y2, m_tileSize, m_tileSize, (id - (tileset.firstGridID - 1)) / tileset.numColumns, (id - (tileset.firstGridID - 1)) % tileset.numColumns, SDLEngine::Instance()->GetRenderer());
        }
    }
}

Tileset TileLayer::GetTilesetByID(int ID)
{
    for(int i = 0; i < m_tilesets.size(); i++)
    {
        if(i + 1 <= m_tilesets.size() - 1)
        {
            if(ID >= m_tilesets[i].firstGridID && ID < m_tilesets[i + 1].firstGridID)
            {
                return m_tilesets[i];
            }
        }
        else
        {
            return m_tilesets[i];
        }
    }
    std::cout << "did not find tileset, returning empty tilset" << std::endl;
    Tileset t;
    return t;
}

TileLayer::TileLayer(int tileSize, int mapWidth, int mapHeight, const std::vector<Tileset> &tileset) : m_tileSize(tileSize),
                                                                        m_tilesets(tileset), m_position(0,0), m_velocity(0,0)
{
    m_numColumns = mapWidth;
    m_numRows = mapHeight;

    m_mapWidth = mapWidth;
    m_mapHeight = mapHeight;
}