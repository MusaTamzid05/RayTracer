#include "computation.h"
#include "intersection.h"

namespace Light {

    Computation::Computation(Intersection* intersection,
            const TwoD::Point& point,
            const TwoD::Vector& eye_vector,
            const TwoD::Vector& normal_vector
            ):
        distance(intersection->distance),
        object(intersection->object),
        point(point),
        eye_vector(eye_vector),
        normal_vector(normal_vector) {

        }

};
