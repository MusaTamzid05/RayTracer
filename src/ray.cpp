#include "ray.h"

namespace Light {

    Ray::Ray(const TwoD::Point& origin, const TwoD::Vector& direction):
        origin(origin),
        direction(direction) {}

    Ray::~Ray() {}


    TwoD::Point Ray::position(float distance) {
        TwoD::Tuple new_direction = direction;
        TwoD::Tuple result = origin + new_direction * distance;
        return TwoD::Point::convert_to_point(result);
    }

    std::ostream& operator<<(std::ostream& out , const Ray& ray) {
        out << "Origin : " << ray.origin << "\n";
        out << "Direction : " << ray.direction;

        return out;
    }

};
