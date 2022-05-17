#include "Level.hpp"

void Level::Update()
{
    for(int i = 0; i < m_layers.size(); i++)
    {
        m_layers[i]->Update();
    }
}

void Level::Render()
{
    for(int i = 0; i < m_layers.size(); i++)
    {
        m_layers[i]->Render();
    }
}