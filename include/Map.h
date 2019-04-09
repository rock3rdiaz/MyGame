#ifndef H_MAP_H
#define H_MAP_H

#include "Game.h"

using namespace std;

namespace rock3r {

    class Map {
        public:
            Map();
            ~Map();
            void loadMap(int arr[20][25]);
            void drawMap();
        private:
            SDL_Texture* dirt;
            SDL_Texture* grass;
            SDL_Texture* water;
            SDL_Rect startRect, endRect;
            int map[20][25];
    };
}

#endif

