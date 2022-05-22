#include <SDLGameObject.hpp>
#include <TextureLoader.hpp>
#include <SDLEngine.hpp>
#include <iostream>
#include <vector>
#include <TileLayer.hpp>

SDLGameObject::SDLGameObject() : GameObject()
{
}

void SDLGameObject::Load(const LoaderParams* pParams)
{
    m_position = Vector2D(pParams->GetX(), pParams->GetY());
    m_velocity = Vector2D(0,0);
    m_acceleration = Vector2D(0,0);
    m_width = pParams->GetWidth();
    m_height = pParams->GetHeight();
    textureID = pParams->GetTextureID();
    currentRow = 2;
    currentFrame = 6;
    m_animSpeed = pParams->GetAnimSpeed();
    m_numFrames = pParams->GetNumFrames();
}

void SDLGameObject::Draw()
{
    /*
    std::cout << "Texture ID object: " << textureID << std::endl;
    std::cout << "x: " << int(m_position.GetX()) << std::endl;
    std::cout << "y: " << int(m_position.GetY()) << std::endl;
    std::cout << "width: " << m_width << std::endl;
    std::cout << "height: " << m_height << std::endl;
    std::cout << "currentRow: " << currentRow << std::endl;
    std::cout << "currentFrame: " << currentFrame << std::endl;
    */
    TextureLoader::Instance()->DrawFrame(textureID, int(m_position.GetX()), int(m_position.GetY()), m_width, m_height, currentRow, currentFrame, Engine::Instance()->GetRenderer());
}

void SDLGameObject::Update()
{
    m_position += m_velocity;
}

void SDLGameObject::Clean()
{
    
}

void SDLGameObject::Collision()
{
    std::cout << "Collision" << std::endl;
}

std::string SDLGameObject::GetTye()
{
    return "SDLGameObject";
}

bool SDLGameObject::CheckCollideTile(Vector2D newPos)
{
    if(newPos.GetY() + m_height >= HEIGHT - 32)
    {
        return false;
    }
    else
    {
        for(std::vector<TileLayer*>::iterator it = m_collisionLayer->begin(); it != m_collisionLayer->end(); ++it)
        {
            TileLayer* pTileLayer = (*it);
            std::vector<std::vector<int> > tiles = pTileLayer->GetTileIDs();

            Vector2D layerPos = pTileLayer->GetPosition();

            int x, y, tileColumn, tileRow, tileid = 0;

            x = layerPos.GetX() / pTileLayer->GetTileSize();
            y = layerPos.GetY() / pTileLayer->GetTileSize();

            Vector2D startPos = newPos;
            startPos.m_x += 15;
            startPos.m_y += 20;
            Vector2D endPos(newPos.GetX() + (m_width - 15), newPos.GetY() + (m_height - 4));

            for(int i = startPos.GetX(); i < endPos.GetX(); i++)
            {
                for(int j = startPos.GetY(); j < endPos.GetY(); j++)
                {
                    tileColumn = i / pTileLayer->GetTileSize();
                    tileRow = j / pTileLayer->GetTileSize();

                    tileid = tiles[tileRow + y][tileColumn + x];

                    if(tileid != 0)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
}