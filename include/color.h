#ifndef COLOR_H
#define COLOR_H

#include "tuple.h"

namespace Engine {

    struct Color: public TwoD::Tuple {

        Color(float r , float g , float b):
            TwoD::Tuple(r , g , b) {}

        float red() { return x; }
        float green() { return y; }
        float blue() { return z; }

    };
}
#endif
