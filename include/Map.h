#ifndef H_MAP_H
#define H_MAP_H

#include <string>


using namespace std;

namespace rock3r {

    class Map {
        public:
            Map();
            ~Map();
            static void loadMap(string path, int sizeX, int sizeY);
        private:
    };
}

#endif

