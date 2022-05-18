#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H
#include <BaseCreator.hpp>
#include <map>
#include <string>
#include <iostream>


class GameObjectFactory
{
public:
    bool RegisterType(std::string typeID, BaseCreator* pCreator)
    {
        std::map<std::string, BaseCreator*>::iterator it = m_creators.find(typeID);

        // if the type is already registered, do nothing
        if(it != m_creators.end())
        {
            delete pCreator;
            return false;
        }

        m_creators[typeID] = pCreator;
        return true;
    }

    GameObject* create(std::string typeID)
    {
        std::map<std::string, BaseCreator*>::iterator it = m_creators.find(typeID);

        if(it == m_creators.end())
        {
            std::cout << "could not find type: " << typeID << std::endl;
            return NULL;
        }

        BaseCreator* pCreator = (*it).second;
        return pCreator->CreateGameObject();
    }

    static GameObjectFactory* Instance()
    {
        if(m_instance == 0) m_instance = new GameObjectFactory();
        return m_instance;
    }
private:
    static GameObjectFactory* m_instance;
    GameObjectFactory() {}
    std::map<std::string, BaseCreator*> m_creators;
};

GameObjectFactory* GameObjectFactory::m_instance = 0;

#endif