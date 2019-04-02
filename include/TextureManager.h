#ifndef H_TEXTURE_MANAGER_H
#define H_TEXTURE_MANAGER_H

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


