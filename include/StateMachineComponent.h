//
// Created by Wake on 4/25/2023.
//

#ifndef SLATFORMER_STATEMACHINECOMPONENT_H
#define SLATFORMER_STATEMACHINECOMPONENT_H
#include "ECS.h"
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <typeindex>
#include <vector>

using namespace std;
class IState
{
public:
    virtual void Tick(){}
    virtual void OnEnter(){}
    virtual void OnExit(){}
};

class Combat : public IState
{
    void Tick() override
    {

    }

    void OnEnter() override
    {
        std::cout << "In Combat" << std::endl;
    }

    void OnExit() override
    {

    }
};

class Transition
{
public:
    Transition(){
        m_condition = nullptr;
        m_to = nullptr;
    }
    Transition(IState* to, function<bool()>* condition)
            : m_to(to), m_condition(condition)
    {
    }

    bool get_condition()
    {
        return m_condition;
    }

    IState* get_to()
    {
        return m_to;
    }

private:
    function<bool()>* m_condition;
    IState* m_to;
};

class StateMachineComponent : public Component
{
public:
    bool Test()
    {
        return false;
    }

    StateMachineComponent()
    {
        auto* combat = new Combat;
        this->SetState(combat);
        bool foo = this->Test();
        this->AddAnyTransition(combat, &foo);
    }

    void Update() override
    {
        Tick();
    }

    void Tick()
    {
        auto transition = GetTransition();

        if(transition.get_to() != nullptr)
        {
            SetState(transition.get_to());
        }

        currentState.Tick();

    }

    void SetState(IState* state)
    {
        if(state == &currentState)
        {
            return;
        }

        currentState.OnExit();

        currentState = *state;

        auto it = transitions.find(typeid(currentState));
        if (it != transitions.end()) {
            currentTransitions.assign(it->second.begin(), it->second.end());
        } else {
            currentTransitions = emptyTransitions;
        }

        currentState.OnEnter();

    }

    void AddAnyTransition(IState* state, function<bool(bool)>* predicate)
    {
        anyTransitions.emplace_back(Transition(state,predicate));
    }

private:
    IState currentState;
    std::map<std::type_index, std::vector<Transition>> transitions;
    list<Transition> currentTransitions;
    list<Transition> anyTransitions;

    list<Transition> emptyTransitions;

    Transition GetTransition()
    {

        for (auto it = anyTransitions.begin(); it != anyTransitions.end(); ++it) {
            bool foo = it->get_condition();
            if(foo)
            {
                if (it->get_condition())
                {
                    return *it;
                }
            }

        }
//        for_each(anyTransitions.begin(), anyTransitions.end(), [](Transition i) {
//            if(i.get_condition() && (i.get_condition()))
//            {
//                return i;
//            }
//        });
//
//        for_each(currentTransitions.begin(), currentTransitions.end(), [](Transition i) {
//            if(i.get_condition() && (i.get_condition()))
//            {
//                return i;
//            }
//        });

        cout << "The Transition Returned Null" << endl;
        return {};
    }

};



#endif //SLATFORMER_STATEMACHINECOMPONENT_H
