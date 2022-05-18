#ifndef BASECREATOR_H
#define BASECREATOR_H
#include <GameObject.hpp>

class BaseCreator
{
public:
    virtual GameObject* CreateGameObject() const = 0;
};

#endif