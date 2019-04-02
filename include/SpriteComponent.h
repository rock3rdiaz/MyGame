#ifndef H_SPRITE_COMPONENT_H
#define H_SPRITE_COMPONENT_H

#include <SDL2/SDL.h>
#include "Components.h"

using namespace std;

namespace rock3r {

    class SpriteComponent : public Component {
        private:
            TransformComponent* transform;
            SDL_Texture* texture;
            SDL_Rect startRect, endRect;
        public:
            SpriteComponent() = default;
            SpriteComponent(const char* path) {
                setText(path);
            };

            void setText(const char* path) {
                texture = TextureManager::loadTexture(path);
            }

            void init() override {
                transform = &entity->getComponent<TransformComponent>();
                startRect.x = startRect.y = 0;
                startRect.w = startRect.h = 32;
                endRect.w = endRect.h = 64;
            };

            void update() override {
                endRect.x = (int) transform->position.x;
                endRect.y = (int) transform->position.y;
            };

            void draw() override {
                TextureManager::draw(texture, startRect, endRect);
            };
    };
}

#endif


