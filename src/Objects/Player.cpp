#include <Player.hpp>
#include <InputHandler.hpp>
#include <iostream>

Player::Player() : m_up(false),
                   m_down(false),
                   m_left(false),
                   m_right(false),
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
    if(InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_S))
    {
        m_down = true;
        currentFrame = 3;
    }
    else
    {
        m_down = false;
    }
    if(InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_W))
    {
        m_up = true;
        currentFrame = 1;
    }
    else
    {
        m_up = false;
    }
    if(InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_A))
    {
        m_left = true;
        currentFrame = 2;
    }
    else
    {
        m_left = false;
    }
    if(InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_D))
    {
        m_right = true;
        currentFrame = 0;
    }
    else
    {
        m_right = false;
    }

}

void Player::Clean()
{

}