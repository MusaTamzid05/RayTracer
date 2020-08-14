#ifndef COMPUTATION_H
#define COMPUTATION_H

#include "vector.h"
#include "point.h"

namespace Light {

    class Intersection;
    class Sphere;
    class Ray;

    struct Computation {

        const Sphere* object;
        float distance;
        float inside;

        TwoD::Point point;
        TwoD::Vector eye_vector;
        TwoD::Vector normal_vector;

        Computation(const Intersection* intersection,
                const Light::Ray* ray
                );


    };
}
#endif
