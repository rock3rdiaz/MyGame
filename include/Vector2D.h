#ifndef H_VECTOR_2D_H
#define H_VECTOR_2D_H

#include <iostream>

using namespace std;

namespace rock3r {

    class Vector2D {
        public:
            float x;
            float y;
            
            Vector2D();
            Vector2D(float _x, float _y) : x(_x), y(_y) {};

            Vector2D& add(const Vector2D& vec);
            Vector2D& substract(const Vector2D& vec);
            Vector2D& multiply(const Vector2D& vec);
            Vector2D& divide(const Vector2D& vec);

            friend Vector2D& operator+(Vector2D& v1, const Vector2D& v2);
            friend Vector2D& operator-(Vector2D& v1, const Vector2D& v2);
            friend Vector2D& operator*(Vector2D& v1, const Vector2D& v2);
            friend Vector2D& operator/(Vector2D& v1, const Vector2D& v2);
            
            Vector2D& operator+=(const Vector2D& vec);
            Vector2D& operator-=(const Vector2D& vec);
            Vector2D& operator*=(const Vector2D& vec);
            Vector2D& operator/=(const Vector2D& vec);

            friend ostream& operator<<(ostream& strea, const Vector2D& vec);
    };
}

#endif 
