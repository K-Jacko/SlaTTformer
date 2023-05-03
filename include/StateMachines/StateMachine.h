#include <iostream>
#include "State.h"


template<class T>
class StateMachine{
    T* m_Owner;
    State<T>* m_CurrentState;
    bool m_firstRun = true;
public:
    void InitSM(T* Owner, State<T>* initialState);
    void UpdateSM();
    void ChangeState(State<T>* newState);
};

template<class T>
inline void StateMachine<T>::InitSM(T* Owner, State<T>* initialState)
{
    m_CurrentState = initialState;
    m_Owner = Owner;
    std::cout << "StateMachine initialized" << std::endl;
}

template<class T>
inline void StateMachine<T>::UpdateSM()
{
    if(m_firstRun)
    {
        m_firstRun = false;
        m_CurrentState->Enter(m_Owner);
    }

    m_CurrentState->Execute(m_Owner);
}

template<class T>
void StateMachine<T>::ChangeState(State<T>* newState)
{
    m_CurrentState->Exit(m_Owner);
    m_CurrentState = newState;
    m_CurrentState->Enter(m_Owner);
}