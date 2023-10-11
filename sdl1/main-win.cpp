#include <SDL.h>

/**
CXX=g++
$CXX main-win.cpp -o main-win `pkg-config --cflags --libs SDL`
*/
int main(int argc, char *argv[]) {
    int quit = 1;
    SDL_Event event;

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_WM_SetCaption("Hello World!", NULL);
    SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
    while (quit) {
        SDL_WaitEvent(&event);
        if (event.type == SDL_QUIT)
            quit = 0;
    }
    SDL_Quit();
    return 0;
}