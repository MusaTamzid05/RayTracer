#ifndef RAY_WORLD_H
#define RAY_WORLD_H

#include <vector>
#include "intersection.h"
#include "color.h"

namespace Light {
    struct PointLight;
    struct Computation;
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
        Light::IntersectionContainer intersect(const Light::Ray* ray);

        Engine::Color shade_hit(Light::Computation* comps);
        Engine::Color color_at(const Light::Ray* ray);

    };
};


#endif
