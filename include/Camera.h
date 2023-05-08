#pragma once
#include "Global.h"
#include "SDL.h"
#include "Math.h"



class Camera {
public:
    static Camera& Instance()
    {
        static Camera instance;
        return instance;
    }
    Camera()
    {
        view.x = 0;
        view.y = 0;
        view.w = gbl::SCREEN::WIDTH * 2;
        view.h = gbl::SCREEN::HEIGHT * 2;
        zoom = 1;
    };

    void Update()
    {
        switch (cameraMovement)
        {
            case gbl::CAMERAMOVEMENT::Follow: {
                view.w = gbl::SCREEN::WIDTH / zoom;
                view.h = gbl::SCREEN::HEIGHT / zoom;

                view.x = (position->x + 21 / 2) - view.w / 2;
                view.y = (position->y + 50 / 2) - view.h / 2;

//                view.x = std::clamp(view.x, 0,static_cast<int>(gbl::SCREEN::WIDTH- view.w) - view.w);
//                view.y = std::clamp(view.y, 0,static_cast<int>(gbl::SCREEN::HEIGHT- view.h)- view.h);
                break;
            }
            case gbl::CAMERAMOVEMENT::Instant:
            {
                view.x = position->x;
                view.y = position->y;

                break;
            }
            case gbl::CAMERAMOVEMENT::Lerp:
                view.x = gbl::lerp(gbl::SCREEN::CAMERA_LERP_SPEED, position->x, view.x);
                view.y = gbl::lerp(gbl::SCREEN::CAMERA_LERP_SPEED, position->y, view.y);

        }
    };
    void SetFollowObject(Vector2D _target)
    {
        target = _target;
    };
    void SetCameraMovement(gbl::CAMERAMOVEMENT _cameramovement)
    {
        cameraMovement = _cameramovement;
    }
    void SetPosition(Vector2D* _position)
    {
        position = _position;
    }
    void SetZoom(int _zoom){zoom = _zoom;}
    SDL_Rect view{0, 0, 0, 0};

private:
    Vector2D* position,target;
    float zoom;
    gbl::CAMERAMOVEMENT cameraMovement = gbl::CAMERAMOVEMENT::Follow;


};