//
// Created by Wake on 2/19/2023.
//

#ifndef SLATFORMER_UTILS_H
#define SLATFORMER_UTILS_H
#include <SDL.h>
namespace utils
{
    inline float hireTimeInSeconds()
    {
        float t = SDL_GetTicks();
        t *= 0.001f;

        return t;
    }
}
#endif //SLATFORMER_UTILS_H
