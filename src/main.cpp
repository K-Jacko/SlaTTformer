#include <iostream>
#include <SDL.h>
#include "Game.h"
#include <windows.h>

Game* game = nullptr;
LARGE_INTEGER frequency;
float get_seconds_per_frame(LARGE_INTEGER start_counter,
                            LARGE_INTEGER end_counter)
{

    return ((float)(end_counter.QuadPart - start_counter.QuadPart) / (float)frequency.QuadPart);
}

int main(int argc, char* args[])
{

    LARGE_INTEGER start_counter, end_counter, counts, fps, ms;
    float target_seconds_per_frame = 1.0f / 120.0f;
    QueryPerformanceCounter(&start_counter);
    QueryPerformanceFrequency(&frequency);


    game = new Game();
    game->Init("Cozy", true);
    while (game->Running())
    {
        QueryPerformanceCounter(&end_counter);

        float seconds_per_frame = get_seconds_per_frame(start_counter,end_counter);

        if(seconds_per_frame < target_seconds_per_frame)
        {
            DWORD sleep_ms;

            sleep_ms = (DWORD)(1000 * (target_seconds_per_frame - seconds_per_frame));

            Sleep(sleep_ms);

            while(seconds_per_frame < target_seconds_per_frame)
            {
                QueryPerformanceCounter(&end_counter);

                seconds_per_frame = get_seconds_per_frame(start_counter,
                                                          end_counter);
            }
        }

        QueryPerformanceCounter(&end_counter);

        seconds_per_frame = get_seconds_per_frame(start_counter,
                                                  end_counter);

        start_counter = end_counter;

        game->deltaTime = seconds_per_frame;

        game->HandleEvents();
        game->Update();
        game->Collision();
        game->Render();
    }
    game->Clean();
    return 0;
}