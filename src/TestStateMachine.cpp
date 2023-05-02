#include "TestStateMachine.h"
#include "TestStates.h"

 TestStateMachine::TestStateMachine() {
    StartState = new class StartState();
    State1 = new class State1();
    State2 = new class State2();
    StateN = new class StateN();
}

 TestStateMachine::~TestStateMachine() {
    delete StartState;
    delete State1;
    delete State2;
    delete StateN;
}

 void TestStateMachine::Update() {
    StateMachine<TestStateMachine>::Update();
}
