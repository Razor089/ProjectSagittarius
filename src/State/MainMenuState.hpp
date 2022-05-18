#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H
#include <State.hpp>
#include <StateMachine.hpp>
#include <Level.hpp>

class MainMenuState : public State<StateMachine>
{
    int wid;
    int heig;
    int pos;
    Level* level;
public:
    void Enter(StateMachine* sm);
    void Update(StateMachine* sm);
    void Render(StateMachine* sm);
    void Exit(StateMachine* sm);
};

#endif