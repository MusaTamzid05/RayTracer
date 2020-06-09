#include "point.h"

namespace TwoD {

    void Point::clear_negative() {

        if(x < 0)
            x = 0.0f;

        if(y < 0)
            y = 0.0f;
    }

};
