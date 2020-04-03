#include "equal.h"
#include <cmath>


namespace Operation {
    bool equal(float x , float y) {
        return std::fabs(x - y) < EPSILON;
    }
};
