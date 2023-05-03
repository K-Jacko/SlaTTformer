//
// Created by Wake on 4/29/2023.
//

#ifndef SLATFORMER_TESTSTATEMACHINE_H
#define SLATFORMER_TESTSTATEMACHINE_H
#include "StateMachine.h"
class TestStateMachine : public StateMachine<TestStateMachine>{
    State<TestStateMachine>* StartState;
    State<TestStateMachine>* State1;
    State<TestStateMachine>* State2;
    State<TestStateMachine>* StateN;

    bool isDone;
public :
    TestStateMachine();
    ~TestStateMachine();
    void Update();
    void Done(){isDone = true;}
    bool HasDone(){return isDone;}

    friend class StartState;
    friend class State1;
    friend class State2;
    friend class StateN;

};

#endif //SLATFORMER_TESTSTATEMACHINE_H
