#include "CollisionManager.hpp"

CollisionManager* CollisionManager::m_instance = 0;

CollisionManager* CollisionManager::Instance()
{
    if(m_instance == 0) m_instance = new CollisionManager();
    return m_instance;
}