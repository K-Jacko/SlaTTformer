#ifndef SLATFORMER_PLAYERSTATES_H
#define SLATFORMER_PLAYERSTATES_H
#include "State.h"

class PStartState : public State <class PlayerStateMachine>
{
    ~PStartState() override{}
public:
    void Enter(PlayerStateMachine* Owner) override;

    void Execute(PlayerStateMachine* Owner) override;

    void Exit(PlayerStateMachine* Owner) override;
};

class PState1 : public State<class PlayerStateMachine>
{
    ~PState1() override= default;
public:
    void Enter(PlayerStateMachine* Owner) override;

    void Execute(PlayerStateMachine* Owner) override;

    void Exit(PlayerStateMachine* Owner);
};
class PState2 : public State<class PlayerStateMachine>
{
    ~PState2(){}
public:
    void Enter(PlayerStateMachine* Owner);

    void Execute(PlayerStateMachine* Owner);

    void Exit(PlayerStateMachine* Owner);
};
class PStateN : public State<class PlayerStateMachine>
{
public:
    void Enter(PlayerStateMachine* Owner);

    void Execute(PlayerStateMachine* Owner);

    void Exit(PlayerStateMachine* Owner);

};
#endif //SLATFORMER_PLAYERSTATES_H
