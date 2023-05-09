#include <iostream>
#include "StateMachines/FishingStates.h"
#include "StateMachines/PlayerStateMachine.h"
#include "Components/Components.h"


void StartFishingState::Enter(PlayerStateMachine *Owner)
{
    std::cout << "IN START STATE" << std::endl;
    Owner->entity->RemoveInput(1);
}

void StartFishingState::Execute(PlayerStateMachine *Owner)
{
    if(!Owner->entity->GetMouseInputs().empty())
    {
        Owner->ChangeState(Owner->PState1);
    }
}

void StartFishingState::Exit(PlayerStateMachine *Owner)
{
    std::cout << "OUT START STATE" << std::endl;
}

void CastFishingState::Enter(PlayerStateMachine *Owner)
{
    startTime = std::chrono::high_resolution_clock::now();
    std::cout << "IN FISHING STATE" << std::endl;
    if(Owner->fLine == nullptr)
    {
        Owner->fLine = &EntityManager::Instance().addEntity();
        Owner->fLine->addComponent<TransformComponent>(Owner->entity->getComponent<TransformComponent>().GetPosition()->x - 30,Owner->entity->getComponent<TransformComponent>().GetPosition()->y - 30,32,32,1,1,5);
        Owner->fLine->getComponent<TransformComponent>().SetArc(gbl::Arc(10, 3));
        Camera::Instance().SetPosition(Owner->fLine->getComponent<TransformComponent>().GetPosition());
        Owner->fLine->addComponent<ColliderComponent>("Bait");
        Owner->fLine->addComponent<SpriteComponent>("resources/Bobber.png",0,0);
    }
    else{
        Owner->fLine->getComponent<SpriteComponent>().IsActive(true);
        Owner->fLine->getComponent<TransformComponent>().SetWidth(32);
        Owner->fLine->getComponent<TransformComponent>().SetHeight(32);
        Owner->fLine->getComponent<TransformComponent>().SetArc(gbl::Arc(10, 3));
        Camera::Instance().SetPosition(Owner->fLine->getComponent<TransformComponent>().GetPosition());
        Owner->fLine->getComponent<TransformComponent>().SetPosition(Owner->entity->getComponent<TransformComponent>().GetPosition()->x - 30,Owner->entity->getComponent<TransformComponent>().GetPosition()->y - 30);
    }



    //CameraTarget = fishingLines->getComponent<TransformComponent>().GetPosition();
}

void CastFishingState::Execute(PlayerStateMachine *Owner)
{
    for (auto& cc : Game::colliders)
    {
        auto result = Collision::AABBFL(Owner->fLine->getComponent<ColliderComponent>(), *cc);
        if(result.direction == gbl::CollisionDirection::Up)
        {

            endTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> elapsed = endTime - startTime;
            //std::cout << "Elapsed time: " << elapsed.count() << " ms\n";
            if(elapsed.count() > 5000)
            {
                Owner->ChangeState(Owner->PState2);

            }
            Owner->hitPoint = *Owner->fLine->getComponent<TransformComponent>().GetPosition();
        }
    }
}

void CastFishingState::Exit(PlayerStateMachine *Owner)
{

    //TODO: Must Pool Fishinglines together to allow multiple collisions and Fishingline management
    std::cout << "OUT FISHING STATE" << std::endl;
}

void PulledFishingState::Enter(PlayerStateMachine *Owner)
{
    if(Owner->ex == nullptr)
    {
        Owner->ex = &EntityManager::Instance().addEntity();
        Owner->ex->addComponent<TransformComponent>(Owner->hitPoint.x,Owner->hitPoint.y - 32,32,32,1);
        Owner->ex->addComponent<ColliderComponent>("!");
        Owner->ex->getComponent<TransformComponent>().SetArc(gbl::Arc(-90, 0.001f));
        Owner->ex->addComponent<SpriteComponent>("resources/Exclimation_Prototype.png");
    }
    else{
        Owner->ex->getComponent<TransformComponent>().SetPosition(Owner->hitPoint.x,Owner->hitPoint.y - 32);
        Owner->ex->getComponent<SpriteComponent>().IsActive(true);
        Owner->ex->getComponent<TransformComponent>().SetArc(gbl::Arc(-90, 0.001f));
        Owner->ex->getComponent<TransformComponent>().SetWidth(32);
        Owner->ex->getComponent<TransformComponent>().SetHeight(32);
    }
}

void PulledFishingState::Execute(PlayerStateMachine *Owner)
{
    if(!Owner->entity->GetMouseInputs().empty())
    {

        Owner->ChangeState(Owner->PStateN);
    }
}

void PulledFishingState::Exit(PlayerStateMachine *Owner)
{

}

void SpawnFishingState::Enter(PlayerStateMachine *Owner)
{
    std::cout << "YOU PULLED!" << std::endl;
    if(Owner->fish == nullptr)
    {
        Owner->fish = &EntityManager::Instance().addEntity();
        Owner->fish->addComponent<TransformComponent>(Owner->hitPoint.x,Owner->hitPoint.y,32,32,1,false,5);
        Owner->fish->getComponent<TransformComponent>().SetArc(gbl::Arc(-90, 0.001f));
        Owner->fish->addComponent<ColliderComponent>("Fish");
        Owner->fish->addComponent<SpriteComponent>("resources/Fish Prototype_1.png",0,0);
    }
    else{
        Owner->fish->getComponent<TransformComponent>().SetPosition(Owner->hitPoint.x,Owner->hitPoint.y);
        Owner->fish->getComponent<TransformComponent>().SetHeight(32);
        Owner->fish->getComponent<TransformComponent>().SetWidth(32);
        Owner->fish->getComponent<TransformComponent>().SetArc(gbl::Arc(-90, 0.001f));
        Owner->fish->getComponent<SpriteComponent>().IsActive(true);
    }


}

void SpawnFishingState::Execute(PlayerStateMachine *Owner)
{
    if(!Owner->entity->GetMouseInputs().empty())
    {
        Owner->ChangeState(Owner->PStartState);

    }
}

void SpawnFishingState::Exit(PlayerStateMachine *Owner)
{
    Camera::Instance().SetPosition(Owner->entity->getComponent<TransformComponent>().GetPosition());
    Owner->fLine->getComponent<SpriteComponent>().IsActive(false);
    Owner->ex->getComponent<SpriteComponent>().IsActive(false);

}
