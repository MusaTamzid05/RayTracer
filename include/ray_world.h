#ifndef RAY_WORLD_H
#define RAY_WORLD_H

#include <vector>
#include "intersection.h"

namespace Light {
    struct PointLight;
    class Sphere;
    class Ray;
};

namespace Engine {
    struct RayWorld {
        Light::PointLight* light;
        std::vector<Light::Sphere*> objects;

        RayWorld();

        bool contains(Light::Sphere* target);

        static RayWorld* create_default_world();
        Light::IntersectionContainer intersect(Light::Ray* ray);

    };
};


#endif
