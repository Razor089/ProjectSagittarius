#include <Player.hpp>

void Player::Load(int x, int y, int width, int height, std::string textureID)
{
    GameObject::Load(x, y, width, height, textureID);
}

void Player::Draw(SDL_Renderer* pRenderer)
{
    GameObject::Render(pRenderer);
}