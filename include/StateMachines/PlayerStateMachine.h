#ifndef SLATFORMER_PLAYERSTATEMACHINE_H
#define SLATFORMER_PLAYERSTATEMACHINE_H
#include "StateMachine.h"
#include "ECS.h"
#include "PlayerStates.h"

class PlayerStateMachine : public Component, public StateMachine<PlayerStateMachine>
{
public:
    State<PlayerStateMachine>* PStartState;
    State<PlayerStateMachine>* PState1;
    State<PlayerStateMachine>* PState2;
    State<PlayerStateMachine>* PStateN;
    void Update() override
    {
        TickMachine();
    };
    bool cs = false;
    bool isDone = false;
    void Done(){isDone = true;}
    void cast(){cs = true;}
    PlayerStateMachine()
    {
        PStartState = new class PStartState();
        PState1 = new class PState1();
        PState2 = new class PState2();
        PStateN = new class PStateN();
        InitSM(this,PStartState);

    };
    ~PlayerStateMachine() override
    {
        delete PStartState;
        delete PState1;
        delete PState2;
        delete PStateN;
    };
};



#endif //SLATFORMER_PLAYERSTATEMACHINE_H
