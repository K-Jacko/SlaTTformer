#ifndef SLATFORMER_PLAYERSTATEMACHINE_H
#define SLATFORMER_PLAYERSTATEMACHINE_H
#include "StateMachine.h"
#include "ECS.h"
#include "FishingStates.h"

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
    //TODO: PUT THIS INTO CollisionResult
    Vector2D hitPoint;
    Entity* fish = nullptr;
    Entity* fLine = nullptr;
    Entity* ex = nullptr;
    bool isDone = false;
    void Done(){isDone = true;}
    PlayerStateMachine()
    {
        PStartState = new class StartFishingState();
        PState1 = new class CastFishingState();
        PState2 = new class PulledFishingState();
        PStateN = new class SpawnFishingState();
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
