#ifndef COMPUTATION_H
#define COMPUTATION_H

#include "vector.h"
#include "point.h"

namespace Light {

    class Intersection;
    class Sphere;

    struct Computation {

        Sphere* object;
        float distance;

        TwoD::Point point;
        TwoD::Vector eye_vector;
        TwoD::Vector normal_vector;

        Computation(Intersection* intersection,
                const TwoD::Point& point = TwoD::Point(0.0f, 0.0f, -1.0f),
                const TwoD::Vector& eye_vector = TwoD::Vector(0.0f, 0.0f, -1.0f),
                const TwoD::Vector& normal_vector = TwoD::Vector(0.0f, 0.0f, -1.0f)
                );


    };
}
#endif
