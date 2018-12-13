#include "TextureManager.h"

namespace rock3r {

    SDL_Texture* TextureManager::loadTexture(const char* textureAssetPath, SDL_Renderer* r) {
        SDL_Surface* surface = IMG_Load(textureAssetPath);
        if(!surface)
            cout << "Error loading asset ... " << SDL_GetError() << endl;
       SDL_Texture* texture = SDL_CreateTextureFromSurface(r, surface);
       SDL_FreeSurface(surface);

       return texture;
    };
}
