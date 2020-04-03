#include "vector.h"

namespace TwoD {

    Vector Vector::negate() {

        Vector zero = Vector(0.0f , 0.0f , 0.0f);
        Tuple result = zero - *this;
        return Vector(result.x , result.y , result.z);
    }

};
