#include "point.h"

namespace TwoD {

    Point Point::convert_to_point(const TwoD::Tuple& data) {
        return TwoD::Point(data.x, data.y, data.z);
    }
};
