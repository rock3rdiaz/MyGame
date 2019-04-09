#include "../include/Collision.h"
#include "../include/ColliderComponent.h"

namespace rock3r {

    bool Collision::AABB(const SDL_Rect& rectA, const SDL_Rect& rectB) {
        if(rectA.x + rectA.w >= rectB.x &&
           rectB.x + rectB.w >= rectA.x &&
           rectA.y + rectA.h >= rectB.y &&
           rectB.y + rectB.h >= rectA.y)
            return true;
        return false;
    }
    
    bool Collision::AABB(const ColliderComponent& colA, const ColliderComponent& colB) {
        if(AABB(colA.collider, colB.collider)) {
            cout << colA.tag << " hit: " << colB.tag << endl;
            return true;
        } else {
            return false;
        }
    }
}
