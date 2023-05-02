#ifndef SLATFORMER_PLAYERSTATEMACHINE_H
#define SLATFORMER_PLAYERSTATEMACHINE_H
#include "StateMachine.h"
#include "ECS.h"
#include "Components.h"

class PlayerStateMachine : public StateMachine<PlayerStateMachine>
{
    State<PlayerStateMachine>* PStartState;
    State<PlayerStateMachine>* PState1;
    State<PlayerStateMachine>* PState2;
    State<PlayerStateMachine>* PStateN;

    bool isDone;
    TransformComponent* playerTransform;
    SpriteComponent* playerSprite;

public:
    friend class PStartState;
    friend class PState1;
    friend class PState2;
    friend class PStateN;

    void Update();
    SpriteComponent* GetSpriteComponent(){return playerSprite;}
    PlayerStateMachine(Entity pEntity);
    void Done(){isDone = true;}
    ~PlayerStateMachine();

};

#endif //SLATFORMER_PLAYERSTATEMACHINE_H
