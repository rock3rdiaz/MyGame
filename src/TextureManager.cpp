#include "TextureManager.h"

namespace rock3r {

    SDL_Texture* TextureManager::loadTexture(const char* textureAssetPath) {
        SDL_Surface* surface = IMG_Load(textureAssetPath);
        if(!surface)
            cout << "Error loading asset ... " << SDL_GetError() << endl;
       SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
       SDL_FreeSurface(surface);

       return texture;
    }
    
    void TextureManager::draw(SDL_Texture* texture, SDL_Rect startRect, SDL_Rect endRect) {
        SDL_RenderCopy(Game::renderer, texture, &startRect, &endRect);
    }
}
