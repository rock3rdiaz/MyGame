#ifndef H_POSITION_COMPONENT_H
#define H_POSITION_COMPONENT_H

#include "Components.h"

namespace rock3r {

    class PositionComponent : public Component {
        private:
            int xPos;
            int yPos;

        public:
            PositionComponent() : xPos(0), yPos(0) {};
            PositionComponent(int x, int y) : xPos(x), yPos(y) {};
            int x() { return xPos; }
            int y() { return yPos; }
            void init() override {
                xPos = yPos = 0;
            }
            void setPos(int x, int y) {
                xPos = x;
                yPos = y;
            }
            void update() override {
                xPos++;
                yPos++;
            }
    };
}

#endif
