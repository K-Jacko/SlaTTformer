#pragma once
#include "Global.h"
#include "SDL.h"
#include "Math.h"

class Camera
{
public:
    Camera(short Width, short Heigth);
    Camera();
    void Update(gbl::CameraMovement cameraMovement, float x,float y);
    SDL_Rect view {0, 0, 0, 0};
};