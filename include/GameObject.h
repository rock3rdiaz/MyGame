#ifndef H_GAME_OBJECT_H
#define H_GAME_OBJECT_H

#include "Game.h"

using namespace std;

namespace rock3r {

    class GameObject {
        public:
            GameObject(const char* textureAsset, int x, int y);
            ~GameObject();
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



