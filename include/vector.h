#ifndef VECTOR_H
#define VECTOR_H


#include "tuple.h"

namespace TwoD {

    struct Vector : public Tuple {
        Vector(float x , float y , float z):
            Tuple(x , y , z , 0.f) {}

    Vector negate();

    };

}

#endif
