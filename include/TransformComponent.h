#ifndef H_TRANSFORM_COMPONENT_H
#define H_TRANSFORM_COMPONENT_H

#include "Vector2D.h"
#include "Components.h"

namespace rock3r {

    class TransformComponent : public Component {
        public:
            Vector2D position;
            Vector2D velocity;
            int speed = 3;
            int height = 32;
            int width = 32;
            int scale = 1;
            
            TransformComponent() {
                position.zero();
            }
            
            TransformComponent(int s) {
                position.zero();
                scale = s;
            }
            
            TransformComponent(float x, float y) {
                position.zero();
            }

            TransformComponent(float x, float y, int h, int w, int s) {
                position.x = x;
                position.y = y;
                height = h;
                width = w;
                scale = s;
            }

            void init() override {
                velocity.zero();
            }

            void update() override {
                position.x += velocity.x * speed;
                position.y += velocity.y * speed;
            }
    };
}

#endif
