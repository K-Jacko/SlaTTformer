#include "Camera.h"
#include "Game.h"

Camera::Camera() = default;
Camera::Camera(short Width, short Heigth)
{
    view.x = gbl::SCREEN::WIDTH / 2;
    view.y = gbl::SCREEN::HEIGHT / 2;
}

void Camera::Update(gbl::CameraMovement cameraMovement, float x,float y)
{
    switch (cameraMovement)
    {
        case gbl::CameraMovement::Follow:
        {
            float camDiffX = x - view.x;
            float camDiffY = y - view.y;

            view.x += gbl::sign(camDiffX) * std::min(gbl::SCREEN::CAMERA_FOLLOW_SPEED, abs(x));
            view.y += gbl::sign(camDiffY) * std::min(gbl::SCREEN::CAMERA_FOLLOW_SPEED, abs(y));
            break;
        }
        case gbl::CameraMovement::Instant:
        {
            view.x = x;
            view.y = y;

            break;
        }
        case gbl::CameraMovement::Lerp:
            view.x = gbl::lerp(gbl::SCREEN::CAMERA_LERP_SPEED, x, view.x);
            view.y = gbl::lerp(gbl::SCREEN::CAMERA_LERP_SPEED, y, view.y);

    }

    Game::SetView(view);
}
