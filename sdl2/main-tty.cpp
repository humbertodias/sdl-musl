#include <iostream>
#include <SDL2/SDL.h>

// Window size
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

/**
CXX=g++
$CXX main-tty.cpp -o main-tty -static `pkg-config --static --cflags --libs SDL2`
*/
using namespace std;
int main(int, char **)
{
    // SDL initialisation
    if (SDL_Init(SDL_INIT_EVENTS) != 0)
    {
        SDL_Log("SDL_Init Error: %s\n", SDL_GetError());
        return -1;
    }

    //SDL_envvars("SDL_VIDEODRIVER","dummy");

    // Window creation and position in the center of the screen
    SDL_Window *window = SDL_CreateWindow("Hello World SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        SDL_Log("SDL_CreateWindow Error: %s\n", SDL_GetError());
        return -1;
    }

    // Keep the main loop until the window is closed (SDL_QUIT event)
    bool quit = false;
    SDL_Event e;
    while (!quit)
    {
        // Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            cout << "Event Type:" << e.type << endl;
            switch (e.type)
            {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_KEYDOWN:
                switch (e.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    quit = true;
                    break;
                default:
                    cout << "Key Down:" << e.key.keysym.sym << endl;
                    break;
                }
            case SDL_KEYUP:
                cout << "Key Up:" << e.key.keysym.sym << endl;
                break;

            default:
                break;
            }
        }
    }

    // Destroy the render, window and finalise SDL
    SDL_Quit();

    return 0;
}
