#include "operation.h"
#include <cmath>


namespace Operation {

    bool equal(float x , float y) {
        return std::fabs(x - y) < EPSILON;
    }

    Engine::Color tupleToColor(const TwoD::Tuple& data) {
        return Engine::Color(data.x , data.y , data.z);
    }
};
