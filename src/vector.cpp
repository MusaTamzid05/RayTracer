#include "vector.h"

namespace TwoD {

    Vector Vector::cross(const Vector& vec) {
        return Vector(y * vec.z - z * vec.y , z * vec.x - x * vec.z , x * vec.y - y * vec.x);
    }

    Vector Vector::convert_to_vector(const TwoD::Tuple& data) {
        return Vector(data.x, data.y, data.z);
    }
};
