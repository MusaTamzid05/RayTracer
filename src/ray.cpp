#include "ray.h"

namespace Light {

    Ray::Ray(const TwoD::Point& origin, const TwoD::Vector& direction):
        origin(origin),
        direction(direction) {}

    Ray::~Ray() {}



};
