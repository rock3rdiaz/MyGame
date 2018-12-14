#ifndef H_TEXTURE_MANAGER_H
#define H_TEXTURE_MANAGER_H

#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include "Game.h"

using namespace std;

namespace rock3r {

    class TextureManager {
        public:
            static SDL_Texture* loadTexture(const char* textureAssetPath);
            static void draw(SDL_Texture* texture, SDL_Rect startRect, SDL_Rect endRect);
    };
}

#endif


