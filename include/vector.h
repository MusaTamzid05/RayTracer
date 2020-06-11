#ifndef VECTOR_H
#define VECTOR_H


#include "tuple.h"

namespace TwoD {

    struct Vector : public Tuple {
        Vector(float x , float y , float z):
            Tuple(x , y , z , 0.f) {}

        Vector cross(const Vector& vec);
        static Vector convert_to_vector(const TwoD::Tuple& data);
    };

};

#endif
