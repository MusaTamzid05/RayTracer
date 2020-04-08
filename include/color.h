#ifndef COLOR_H
#define COLOR_H

#include "tuple.h"

namespace Engine {

    struct Color: public TwoD::Tuple {

        Color(float r , float g , float b):
            TwoD::Tuple(r , g , b , 0.0f) {}

        float red() const  { return x; }
        float green() const { return y; }
        float blue() const { return z; }

        Color  hadamard_product(const Color& color) const;

    };
}
#endif
