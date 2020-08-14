#include "ray_world.h"
#include "sphere.h"
#include "point_light.h"
#include "color.h"
#include "material.h"
#include "ray.h"
#include "computation.h"

namespace Engine {
    RayWorld::RayWorld():
        light(nullptr) {

    }


    RayWorld* RayWorld::create_default_world() {

        RayWorld* ray_world = new  Engine::RayWorld();
        ray_world->light = new Light::PointLight(new Engine::Color(1.0f, 1.0f, 1.0f),
                new TwoD::Point(-10.0f, 10.0f, -10.0f)
                );

        Light::Sphere* s1 = new Light::Sphere();
        Light::Material* material = new Light::Material();
        material->color = Engine::Color(0.8f, 1.0f, 0.6f);

        material->diffuse = 0.7f;
        material->specular = 0.2f;

        s1->material = material;

        Light::Sphere* s2 = new Light::Sphere();
        s2->set_transform(TwoD::Matrix4x4::scale(TwoD::Point(0.5f, 0.5f, 0.5f)));

        ray_world->objects.push_back(s1);
        ray_world->objects.push_back(s2);

        return ray_world;
    }


    bool RayWorld::contains(Light::Sphere* target) {

        for(Light::Sphere* sphere : objects)
            if(*sphere == *target)
                return true;

        return false;
    }

    Light::IntersectionContainer RayWorld::intersect(Light::Ray* ray) {

        Light::IntersectionContainer container = Light::IntersectionContainer();

        for(Light::Sphere* obj : objects) 
            container += obj->intersect(*ray);

        return container;
    }


    Engine::Color RayWorld::shade_hit(Light::Computation* comps) {
        return comps->object->material->lighting(light, comps->point, comps->eye_vector, comps->normal_vector);
    }
};
