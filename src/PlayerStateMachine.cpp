#include "PlayerStateMachine.h"
#include "PlayerStates.h"

PlayerStateMachine::PlayerStateMachine(Entity pEntity)
{
    PStartState = new class PStartState();
    PState1 = new class PState1();
    PState2 = new class PState2();
    PStateN = new class PStateN();

}

PlayerStateMachine::~PlayerStateMachine()
{
    delete PStartState;
    delete PState1;
    delete PState2;
    delete PStateN;
}


void PlayerStateMachine::Update() {
    StateMachine<PlayerStateMachine>::Update();
}
