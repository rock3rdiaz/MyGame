#ifndef H_GAME_H
#define H_GAME_H

#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include <filesystem>
#include "TextureManager.h"
#include "GameObject.h"

using namespace std;

namespace rock3r {

    class Game {
        public:
            Game();
            ~Game() = default;
            void init(const char* title, int posX, int posY, int width, int height, bool fullScreen);
            void handleEvents();
            void update();
            void render();
            void clean();
            inline bool running() { return isRunning; }
        private:
            bool isRunning;
            SDL_Window* window;
            SDL_Renderer* renderer;
            GameObject playerObject;
    };
}

#endif

