#include "test_ray_world.h"
#include "ray_world.h"
#include "point.h"
#include "point_light.h"
#include "color.h"
#include "sphere.h"
#include "material.h"
#include <algorithm>

namespace Testing {

    void TestRayWorld::setUp(){}
    void TestRayWorld::tearDown(){}

    void TestRayWorld::testCreateWorld() {

        Engine::RayWorld* ray_world = new Engine::RayWorld();
        CPPUNIT_ASSERT(ray_world->light == nullptr);
        CPPUNIT_ASSERT(ray_world->objects.size() == 0);
    }



    void TestRayWorld::testDefaultWorld() {

        Engine::RayWorld* ray_world = Engine::RayWorld::create_default_world();


        Light::PointLight* light = new Light::PointLight(new Engine::Color(1.0f, 1.0f, 1.0f),
                new TwoD::Point(-10.0f, -10.0f, -10.0f)
                );


        Light::Sphere* s1 = new Light::Sphere();
        Light::Material* material = new Light::Material();
        material->color = Engine::Color(0.8f, 1.0f, 0.6f);

        material->ambient = 0.0f;
        material->shininess= 0.0f;
        material->diffuse = 0.7f;
        material->specular = 0.2f;

        s1->material = material;

        Light::Sphere* s2 = new Light::Sphere();
        s2->set_transform(TwoD::Matrix4x4::scale(TwoD::Point(0.5f, 0.5f, 0.5f)));
        CPPUNIT_ASSERT(*ray_world->light == *light);
        CPPUNIT_ASSERT(ray_world->contains(s1) == true);
        CPPUNIT_ASSERT(ray_world->contains(s2) == true);
    }
};
