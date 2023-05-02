//
// Created by Wake on 4/29/2023.
//

#ifndef SLATFORMER_STATE_H
#define SLATFORMER_STATE_H
template<class T>
class State
{
public:
    virtual ~State(){}
    virtual void Enter(T* Owner){}
    virtual void Execute(T* Owner){}
    virtual void Exit(T* Owner){}
};
#endif //SLATFORMER_STATE_H
