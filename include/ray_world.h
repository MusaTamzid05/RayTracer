#ifndef RAY_WORLD_H
#define RAY_WORLD_H

#include <vector>

namespace Light {
    struct PointLight;
    class Sphere;
};

namespace Engine {
    struct RayWorld {
        Light::PointLight* light;
        std::vector<Light::Sphere*> objects;

        RayWorld();

        bool contains(Light::Sphere* target);

        static RayWorld* create_default_world();
    };
};


#endif
