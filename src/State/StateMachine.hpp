#ifndef STATEMACHINE_H
#define STATEMACHINE_H
#include "State.hpp"

class StateMachine
{
    State<StateMachine>* current;
    static StateMachine* pInstance;
public:
    static StateMachine* Instance();
    void ChangeState(State<StateMachine>* nState);
    void Update();
    void Render();
private:
    StateMachine() : current(0)
    {}
};

#endif