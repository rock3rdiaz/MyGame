#ifndef H_SPRITE_COMPONENT_H
#define H_SPRITE_COMPONENT_H

#include <SDL2/SDL.h>
#include "Components.h"
#include "TextureManager.h"

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

            ~SpriteComponent() {
                SDL_DestroyTexture(texture);
            }

            void setText(const char* path) {
                texture = TextureManager::loadTexture(path);
            }

            void init() override {
                transform = &entity->getComponent<TransformComponent>();
                startRect.x = startRect.y = 0;
                startRect.w = transform->width;
                startRect.h = transform->height;
            };

            void update() override {
                endRect.x = static_cast<int>(transform->position.x);
                endRect.y = static_cast<int>(transform->position.y);
                endRect.w = transform->width * transform->scale;
                endRect.h = transform->height * transform->scale;
            };

            void draw() override {
                TextureManager::draw(texture, startRect, endRect);
            };
    };
}

#endif


