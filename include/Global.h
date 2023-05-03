#pragma once
#include <chrono>

namespace gbl
{
    namespace GAME
    {
        constexpr float GRAVITY = 9.81f;
        constexpr float MAX_VERTICAL_SPEED = 8;

        constexpr unsigned char CELL_SIZE = 25;
    }

    namespace PLAYER
    {
        constexpr float ACCELERATION_RATE = 1;
        constexpr float JUMP_SPEED = -8;
        constexpr float MAX_HORIZONTAL_SPEED = 4;
    }

    namespace SCREEN
    {
        constexpr float CAMERA_FOLLOW_SPEED = 2;
        constexpr float CAMERA_LERP_SPEED = 0.125f;

        constexpr unsigned char RESIZE = 2;

        constexpr unsigned short HEIGHT = 768;
        constexpr unsigned short WIDTH = 1366;

        constexpr std::chrono::microseconds FRAME_DURATION(16667);
    }

    enum CameraMovement
    {
        Follow,
        Instant,
        Lerp
    };

    struct GridObject
    {
        GridObject(){
            X = 0;
            Y = 0;
            ID = -100;
        }
        ~GridObject(){}
        int ID;
        int X,Y;

    };

    template <typename value_type>
    char sign(const value_type i_value)
    {
        return (0 < i_value) - (0 > i_value);
    }

    template <typename value_type = float>
    float lerp(value_type speed, value_type a, int b)
    {
        return a + (b - a) * speed;
    }
}