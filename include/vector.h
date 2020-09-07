#ifndef VECTOR_H
#define VECTOR_H


#include "tuple.h"

namespace TwoD {

    struct Vector : public Tuple {
        Vector(float x = 0.0f , float y = 0.0f , float z = 0.0f):
            Tuple(x , y , z , 0.f) {}

        Vector cross(const Vector& vec) const;
        static Vector convert_to_vector(const TwoD::Tuple& data);

        Vector reflect(const Vector& vec1);
    };

};

#endif
