//
// Created by Wake on 4/29/2023.
//

#ifndef SLATFORMER_TESTSTATES_H
#define SLATFORMER_TESTSTATES_H
#include "TestStateMachine.h"

class StartState : public State<class TestStateMachine>
{
public:
    void Enter(TestStateMachine* Owner)
    {

    }
    void Execute(TestStateMachine* Owner);
    void Exit(TestStateMachine* Owner)
    {

    }
};

class State1 : public State<class TestStateMachine>
{
public:
    void Enter(TestStateMachine* Owner)
    {

    }
    void Execute(TestStateMachine* Owner);
    void Exit(TestStateMachine* Owner)
    {

    }
};

class State2 : public State<class TestStateMachine>
{
public:
    void Enter(TestStateMachine* Owner)
    {

    }
    void Execute(TestStateMachine* Owner);
    void Exit(TestStateMachine* Owner)
    {

    }
};

class StateN : public State<class TestStateMachine>
{
public:
    void Enter(TestStateMachine* Owner)
    {

    }
    void Execute(TestStateMachine* Owner);
    void Exit(TestStateMachine* Owner)
    {

    }
};

inline void StartState::Execute(TestStateMachine *Owner) {
    //Monster spawns
}
inline void State1::Execute(TestStateMachine *Owner) {
    //Monster Idle/Roams
}
inline void State2::Execute(TestStateMachine *Owner) {
    //Monster Combat
}
inline void StateN::Execute(TestStateMachine *Owner) {
    //Monster Dead
}

#endif //SLATFORMER_TESTSTATES_H
