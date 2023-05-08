#include <iostream>
#include "StateMachines/PlayerStates.h"
#include "StateMachines/PlayerStateMachine.h"
#include "Components/Components.h"


void PStartState::Enter(PlayerStateMachine *Owner)
{
    std::cout << "IN START STATE" << std::endl;
}

void PStartState::Execute(PlayerStateMachine *Owner)
{
    if(!Owner->entity->GetMouseInputs().empty())
    {
        Owner->ChangeState(Owner->PState1);
    }
}

void PStartState::Exit(PlayerStateMachine *Owner)
{
    std::cout << "OUT START STATE" << std::endl;
}

void PState1::Enter(PlayerStateMachine *Owner)
{
    std::cout << "IN FISHING STATE" << std::endl;
    auto fishingLines = new Entity();
    Manager::Instance().addEntityRemote(fishingLines);
    fishingLines->addComponent<TransformComponent>(Owner->entity->getComponent<TransformComponent>().GetPosition()->x - 30,Owner->entity->getComponent<TransformComponent>().GetPosition()->y - 30,32,32,1,1,5);
    fishingLines->getComponent<TransformComponent>().SetArc(gbl::Arc(180, 6));
    fishingLines->addComponent<ColliderComponent>("Bait");
    fishingLines->addComponent<SpriteComponent>("resources/Bobber.png",0,0);

    //CameraTarget = fishingLines->getComponent<TransformComponent>().GetPosition();
}

void PState1::Execute(PlayerStateMachine *Owner)
{
    if(Owner->entity->GetMouseInputs().empty())
    {
        Owner->ChangeState(Owner->PStartState);
    }
}

void PState1::Exit(PlayerStateMachine *Owner)
{
    std::cout << "OUT FISHING STATE" << std::endl;
}

void PState2::Enter(PlayerStateMachine *Owner)
{

}

void PState2::Execute(PlayerStateMachine *Owner)
{

}

void PState2::Exit(PlayerStateMachine *Owner)
{

}

void PStateN::Enter(PlayerStateMachine *Owner)
{

}

void PStateN::Execute(PlayerStateMachine *Owner)
{

}

void PStateN::Exit(PlayerStateMachine *Owner)
{

}
