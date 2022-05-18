#include <SDLGameObject.hpp>
#include <TextureLoader.hpp>
#include <SDLEngine.hpp>

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
    TextureLoader::Instance()->DrawFrame(textureID, int(m_position.GetX()), int(m_position.GetY()), m_width, m_height, currentRow, currentFrame, Engine::Instance()->GetRenderer());
}

void SDLGameObject::Update()
{
    m_position += m_velocity;
}

void SDLGameObject::Clean()
{
    
}