#include <SDL.h>
#include <iostream>

/**
CXX=g++
$CXX main-win.cpp -o main-win `pkg-config --cflags --libs SDL`
*/
using namespace std;
int main(int argc, char *argv[]) {
    int init = SDL_Init(SDL_INIT_EVERYTHING);
    cout << "init:" << init << endl;
    SDL_Quit();
    return 0;
}