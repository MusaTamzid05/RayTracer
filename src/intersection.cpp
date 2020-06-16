#include "intersection.h"
#include "sphere.h"

namespace Light {
    Intersection::Intersection(float distance, Light::Sphere* sphere):
    distance(distance),
    sphere(sphere) {

    }
};


