#include "point.h"

namespace TwoD {

    Point Point::convert_to_point(const TwoD::Tuple& data) {
        TwoD::Point point(data.x, data.y, data.z);
        point.w = data.w;
        return point;
    }
};
