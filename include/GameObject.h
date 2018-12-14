#ifndef H_GAME_OBJECT_H
#define H_GAME_OBJECT_H

#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

namespace rock3r {

    class GameObject {
        public:
            GameObject() = default;
            GameObject(const char* textureAsset, int x, int y);
            ~GameObject() = default;
            void update();
            void render();
        private:
            int xPos;
            int yPos;
            SDL_Texture* objectTexture;
            SDL_Rect startRect, endRect; 
    };
}

#endif



