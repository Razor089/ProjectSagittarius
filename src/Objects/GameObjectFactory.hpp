#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H
#include <BaseCreator.hpp>
#include <map>
#include <string>


class GameObjectFactory
{
public:
    bool RegisterType()
    {
        std::map<std::string, BaseCreator*>::iterator it;
    }
};

#endif