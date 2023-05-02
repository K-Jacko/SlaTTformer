//
// Created by Wake on 4/29/2023.
//

#ifndef SLATFORMER_EVENTGENERATOR_H
#define SLATFORMER_EVENTGENERATOR_H
#include <iostream>
#define MAX_COUNTER 5

class EventGenerator{
    int counter;
    EventGenerator()
    {
        counter = rand()%MAX_COUNTER+1;
    }
public:
    static EventGenerator*GetInstance();
    void CleanUp()
    {

    }

    int Generate(int eventNum);
};
#endif //SLATFORMER_EVENTGENERATOR_H
