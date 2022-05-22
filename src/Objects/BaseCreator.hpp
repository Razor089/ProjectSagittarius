#ifndef BASECREATOR_H
#define BASECREATOR_H
#include <GameObject.hpp>

class BaseCreator
{
public:
    virtual GameObject* CreateGeameObject() const = 0;
    virtual ~BaseCreator() {}
};

#endif