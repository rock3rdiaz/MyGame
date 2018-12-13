#include "TextureManager.h"
#include "GameObject.h"

namespace rock3r {

    GameObject::GameObject(const char* textureAsset, SDL_Renderer* r) {
        renderer = r;
        objectTexture = TextureManager::loadTexture(textureAsset, r);  
    };

    void GameObject::update() {
        xPos = 0;
        yPos = 0;

        startRect.h = 32;
        startRect.w = 32;
        startRect.x = 0;
        startRect.y = 0;

        endRect.x = xPos;
        endRect.y = yPos;
        endRect.w = startRect.w * 2;
        endRect.h = startRect.h * 2;
    };

    void GameObject::render() {
        SDL_RenderCopy(renderer, objectTexture, &startRect, &endRect);
    };
}

