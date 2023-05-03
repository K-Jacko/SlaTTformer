#ifndef SLATFORMER_PLAYERSTATEMACHINE_H
#define SLATFORMER_PLAYERSTATEMACHINE_H
#include "StateMachine.h"
#include "ECS.h"
#include "Components/Components.h"
class PStartState : public State <class PlayerStateMachine>
{
    ~PStartState(){}
public:
    void Enter(PlayerStateMachine* Owner)
    {
        std::cout << "IN START STATE" << std::endl;
    }

    void Execute(PlayerStateMachine* Owner)
    {
        //if spawn animation done goto State1
    }

    void Exit(PlayerStateMachine* Owner)
    {

    }
};
class PState1 : public State<class PlayerStateMachine>
{
    ~PState1() override{}
public:
    void Enter(PlayerStateMachine* Owner)
    {

    }
    void Execute(PlayerStateMachine* Owner)
    {
        //if Attacked(Health reduced &or enemy in range goTo State2
    }
    void Exit(PlayerStateMachine* Owner)
    {

    }
};
class PState2 : public State<class PlayerStateMachine>
{
    ~PState2(){}
public:
    void Enter(PlayerStateMachine* Owner)
    {

    }
    void Execute(PlayerStateMachine* Owner)
    {
        //if AttackedCooldown depleted goto State1
        //if Killed goto StateN
    }
    void Exit(PlayerStateMachine* Owner)
    {

    }
};
class PStateN : public State<class PlayerStateMachine>
{
public:
//    ~PStateN(){}
//    void Enter(PlayerStateMachine* Owner)
//    {
//        Owner->Done();
//    }

};
class PlayerStateMachine : public Component, public StateMachine<PlayerStateMachine>
{
    State<PlayerStateMachine>* PStartState;
    State<PlayerStateMachine>* PState1;
    State<PlayerStateMachine>* PState2;
    State<PlayerStateMachine>* PStateN;

    bool isDone;
    TransformComponent* playerTransform;
    SpriteComponent* playerSprite;

public:


    void Update() override
    {
        UpdateSM();
    };
    SpriteComponent* GetSpriteComponent(){return playerSprite;}
    void Done(){isDone = true;}
    PlayerStateMachine()
    {
        PStartState = new class PStartState();
        PState1 = new class PState1();
        PState2 = new class PState2();
        PStateN = new class PStateN();
        InitSM(this,PStartState);

    };
    ~PlayerStateMachine()
    {
        delete PStartState;
        delete PState1;
        delete PState2;
        delete PStateN;
    };

};

#endif //SLATFORMER_PLAYERSTATEMACHINE_H
