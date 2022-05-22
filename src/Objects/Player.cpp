#include <Player.hpp>
#include <InputHandler.hpp>
#include <iostream>

Player::Player() : m_up(false),
                   m_down(false),
                   m_left(false),
                   m_right(false),
                   last_direction(6),
                   SDLGameObject()
{}

void Player::Load(const LoaderParams* pParams)
{
    SDLGameObject::Load(pParams);
}

void Player::Draw()
{
    SDLGameObject::Draw();
}

void Player::Update()
{
    HandleInputs();
    Move();

    //if(m_down || m_up || m_left || m_right)
    //{
        m_currentFrame += int(SDL_GetTicks() / 125 / m_animSpeed) % m_numFrames; 
    //}
}

void Player::Move()
{
    if(m_up) m_velocity.SetY(-2);
    if(m_down) m_velocity.SetY(2);
    if(m_left) m_velocity.SetX(-2);
    if(m_right) m_velocity.SetX(2);
    m_position += m_velocity;
    m_velocity *= 0;
}

void Player::HandleInputs()
{
    // DOWN
  
    if(InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_S))
    {
        m_down = true;
        m_left = false;
        m_right = false;
        m_up = false;
        m_currentFrame = 18;
        m_currentRow = 3;
        last_direction = 18;
    } 
    else if(InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_W))
    {
        m_up = true;
        m_down = false;
        m_left = false;
        m_right = false;
        m_currentFrame = 6;
        m_currentRow = 3;
        last_direction = 6;
    }
    else if(InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_A))
    {
        m_left = true;
        m_right = false;
        m_up = false;
        m_down = false;
        m_currentFrame = 12;
        m_currentRow = 3;
        last_direction = 12;
    }
    else if(InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_D))
    {
        m_right = true;
        m_left = false;
        m_up = false;
        m_down = false;
        m_currentFrame = 0;
        m_currentRow = 3;
        last_direction = 0;
    }
    else
    {
        m_up = m_down = m_left = m_right = false;
        m_currentFrame = last_direction;
        m_currentRow = 2;
    }

}

void Player::Clean()
{

}