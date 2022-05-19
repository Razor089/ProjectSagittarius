#include <SDLGameObject.hpp>
#include <TextureLoader.hpp>
#include <SDLEngine.hpp>
#include <iostream>

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
    currentRow = 1;
    currentFrame = 1;
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