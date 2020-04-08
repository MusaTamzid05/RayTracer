#include "operation.h"
#include <cmath>


namespace Operation {

    bool equal(float x , float y) {
        return std::fabs(x - y) < EPSILON;
    }

    Engine::Color tupleToColor(const TwoD::Tuple& data) {
        return Engine::Color(data.x , data.y , data.z);
    }

    
    int scale_int(float value , float max_value) {

        int result = value *  max_value;

        if (result < 0)
            result = 0;
        else if(result > (int)max_value)
            result = (int)max_value;

        return result;
    }
};
