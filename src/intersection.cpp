#include "intersection.h"
#include "sphere.h"

namespace Light {
    Intersection::Intersection(float distance, Light::Sphere* object):
        distance(distance),
        object(object){

    }
};


