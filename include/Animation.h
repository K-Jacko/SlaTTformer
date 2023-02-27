#ifndef SLATFORMER_ANIMATION_H
#define SLATFORMER_ANIMATION_H

struct Animation
{
    int index, frames, speed;

    Animation() {}
    Animation(int i, int j, int s)
    {
        index = i;
        frames = j;
        speed = s;
    }


};
#endif //SLATFORMER_ANIMATION_H
