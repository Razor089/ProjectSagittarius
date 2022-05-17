#ifndef STATE_H
#define STATE_H

template<class Entity>
class State
{
public:
    virtual void Enter(Entity*)=0;
    virtual void Update(Entity*)=0;
    virtual void Render(Entity*)=0;
    virtual void Exit(Entity*)=0;
};

#endif 