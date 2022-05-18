#ifndef OBJECTLAYER_H
#define OBJECTLAYER_H
#include "Layer.hpp"
#include "GameObject.hpp"
#include <vector>

class ObjectLayer : public Layer
{
public:
    virtual void Update();
    virtual void Render();
    std::vector<GameObject*>* GetGameObjects() { return &m_gameObjects;}
private:
    std::vector<GameObject*> m_gameObjects;
};

#endif