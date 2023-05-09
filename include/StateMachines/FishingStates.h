#ifndef SLATFORMER_FISHINGSTATES_H
#define SLATFORMER_FISHINGSTATES_H
#include "State.h"
#include "ECS.h"
#include "Global.h"

class StartFishingState : public State <class PlayerStateMachine>
{
    ~StartFishingState() override{}
public:
    void Enter(PlayerStateMachine* Owner) override;

    void Execute(PlayerStateMachine* Owner) override;

    void Exit(PlayerStateMachine* Owner) override;
};

class CastFishingState : public State<class PlayerStateMachine>
{
    ~CastFishingState() override= default;
public:
    void Enter(PlayerStateMachine* Owner) override;

    void Execute(PlayerStateMachine* Owner) override;

    void Exit(PlayerStateMachine* Owner);
private:
    std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<double, std::ratio<1>>> endTime,startTime;
};
class PulledFishingState : public State<class PlayerStateMachine>
{
    ~PulledFishingState(){}
public:
    void Enter(PlayerStateMachine* Owner);

    void Execute(PlayerStateMachine* Owner);

    void Exit(PlayerStateMachine* Owner);

};
class SpawnFishingState : public State<class PlayerStateMachine>
{
public:
    void Enter(PlayerStateMachine* Owner);

    void Execute(PlayerStateMachine* Owner);

    void Exit(PlayerStateMachine* Owner);
private:

};
#endif //SLATFORMER_FISHINGSTATES_H
