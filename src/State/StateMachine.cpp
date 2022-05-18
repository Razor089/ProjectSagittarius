#include <StateMachine.hpp>

StateMachine* StateMachine::pInstance = 0;

StateMachine* StateMachine::Instance()
{
    if(pInstance == 0) pInstance = new StateMachine();
    return pInstance;
}

void StateMachine::ChangeState(State<StateMachine>* nState)
{
    if(current != 0) current->Exit(this);

    current = nState;

    current->Enter(this);
}

void StateMachine::Update()
{
    if(current != 0) current->Update(this);
}

void StateMachine::Render()
{
    if(current != 0) current->Render(this);
}