#ifndef H_GAME_H
#define H_GAME_H

#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>

using namespace std;

namespace rock3r {

    class Game {
        public:
            Game() = default;
            ~Game() = default;
            void init(const char* title, int posX, int posY, int width, int height, bool fullScreen);
            void handleEvents();
            void update();
            void render();
            void clean();
            inline bool running() { return isRunning; }
            static SDL_Renderer* renderer;
        private:
            bool isRunning = false;
            SDL_Window* window;
    };
}

#endif

