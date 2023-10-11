#include <SDL.h>
#include <iostream>

/**
CXX=g++
$CXX main-tty.cpp -o main-tty `pkg-config --cflags --libs SDL`

$CXX main-tty.cpp -o main-tty -I_deps/sdl1-src/include/SDL -L_deps/sdl1-build -lSDLmain -lSDL-1.2.0 -lm -liconv -Wl,-framework,Cocoa
*/
using namespace std;
int main(int argc, char *argv[]) {
    int init = SDL_Init(SDL_INIT_EVERYTHING);
    cout << "init:" << init << endl;
    SDL_Quit();
    return 0;
}