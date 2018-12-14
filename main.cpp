#include <iostream>
#include <SDL2/SDL.h>
#include "Game.h"

using namespace rock3r;
using namespace std;

int main() {

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    int32_t frameStart;
    int frameTime;

    Game game;
    game.init("rocker", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 680, 480, false);

    while(game.running()) {

        frameStart = SDL_GetTicks();

        game.handleEvents();
        game.update();
        game.render();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime);
    }

    game.clean();
    return 0;
}
