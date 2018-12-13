#ifndef H_TEXTURE_MANAGER_H
#define H_TEXTURE_MANAGER_H

#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>

using namespace std;

namespace rock3r {

    class TextureManager {
        public:
            static SDL_Texture* loadTexture(const char* textureAssetPath, SDL_Renderer* r);
    };
}

#endif


