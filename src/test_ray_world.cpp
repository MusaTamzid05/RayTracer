#include "test_ray_world.h"
#include "ray_world.h"
#include "point.h"
#include "point_light.h"
#include "color.h"
#include "sphere.h"
#include "material.h"
#include "ray.h"
#include "computation.h"
#include "operation.h"



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
                new TwoD::Point(-10.0f, 10.0f, -10.0f)
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


    void TestRayWorld::testIntersectWorldWithRay() {

        Engine::RayWorld* ray_world = Engine::RayWorld::create_default_world();

        TwoD::Point origin = TwoD::Point(0.0f, 0.0f, -5.0f);
        TwoD::Vector direction = TwoD::Vector(0.0f, 0.0f, 1.0f);

        Light::Ray ray(origin, direction);

        Light::IntersectionContainer container = ray_world->intersect(&ray);
        CPPUNIT_ASSERT(container.size() == 4);

        CPPUNIT_ASSERT(container.get(0).distance == 4.0f);
        CPPUNIT_ASSERT(container.get(1).distance == 4.5f);
        CPPUNIT_ASSERT(container.get(2).distance == 5.5f);
        CPPUNIT_ASSERT(container.get(3).distance == 6.0f);

    }


    void TestRayWorld::testShadingIntersection() {
        
        Engine::RayWorld* ray_world = Engine::RayWorld::create_default_world();
        Light::Ray ray(TwoD::Point(0.0f, 0.0f, -5.0f), TwoD::Vector(0.0f, 0.0f, 1.0f));
        Light::Sphere* shape = ray_world->objects[0];
        Light::Intersection* intersection = new Light::Intersection(4.0f, shape);

        Light::Computation* computation = new Light::Computation(intersection, &ray);
        Engine::Color color = ray_world->shade_hit(computation);

        CPPUNIT_ASSERT(Operation::equal(color.red(), 0.38066));
        CPPUNIT_ASSERT(Operation::equal(color.green(), 0.47583));
        CPPUNIT_ASSERT(Operation::equal(color.blue(), 0.2855));



    }

    void TestRayWorld::testShadingAnIntersectionFromInside() {

        Engine::RayWorld* ray_world = Engine::RayWorld::create_default_world();
        ray_world->light = new Light::PointLight(new Engine::Color(1.0f, 1.0f, 1.0f),new TwoD::Point(0.0f, 0.25f, 0.0f));
        Light::Ray ray(TwoD::Point(0.0f, 0.0f, 0.0f), TwoD::Vector(0.0f, 0.0f, 1.0f));
        Light::Sphere* shape = ray_world->objects[1];
        Light::Intersection* intersection = new Light::Intersection(0.5f, shape);

        Light::Computation* computation = new Light::Computation(intersection, &ray);
        Engine::Color color = ray_world->shade_hit(computation);
        CPPUNIT_ASSERT(color == TwoD::Vector(0.90498f, 0.90498f, 0.90498f));
    }
};
