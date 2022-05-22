#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H
#include <map>
#include <string>
#include <iostream>
#include <GameObject.hpp>
#include <BaseCreator.hpp>


class GameObjectFactory
{
public:
    bool RegisterType(std::string typeID, BaseCreator* pCreator)
    {
        std::map<std::string, BaseCreator*>::iterator it = m_creators.find(typeID);

        // if the type is already registered, do nothing
        if(it != m_creators.end())
        {
            std::cout << "Type: " << typeID << "already registered" << std::endl;
            delete pCreator;
            return false;
        }

        m_creators[typeID] = pCreator;
        std::cout << "Registered type: " << typeID << std::endl;
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

#endif