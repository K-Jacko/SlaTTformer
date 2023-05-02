#include "EventGenerator.h"

EventGenerator*EventGenerator::GetInstance() {
    static EventGenerator Instance;
    return &Instance;
}

int EventGenerator::Generate(int eventNum)
{
    if(counter == 0)
    {
        counter = rand()%MAX_COUNTER+1;
        if(eventNum > 1)
            return rand()%eventNum;
        return 1;
    } else{
        counter--;
    }
    return 0;
}