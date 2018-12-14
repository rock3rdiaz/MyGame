#include "TextureManager.h"
#include "GameObject.h"

namespace rock3r {

    GameObject::GameObject(const char* textureAsset, int x, int y) {
        cout << "GameObject created ..." << endl;
        xPos = x;
        yPos = y;
        objectTexture = TextureManager::loadTexture(textureAsset);  
    };

    void GameObject::update() {
        xPos++;
        yPos++;

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
        SDL_RenderCopy(Game::renderer, objectTexture, &startRect, &endRect);
    };
}

