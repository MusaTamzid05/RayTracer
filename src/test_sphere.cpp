#include "test_sphere.h"
#include "ray.h"
#include "point.h"
#include "vector.h"
#include "sphere.h"
#include "intersection.h"
#include <iostream>

namespace Testing {

    void TestSphere::setUp() {

    }

    void TestSphere::tearDown() {

    }

    void TestSphere::testInterspectsTwoSphere() {

        Light::Ray ray(TwoD::Point(0.0f, 0.0f, -5.0f), TwoD::Vector(0.0f, 0.0f, 1.0f));
        Light::Sphere sphere;

        std::vector<Light::Intersection> intersections = sphere.intersect(ray);

        CPPUNIT_ASSERT(intersections.size() == 2);
        CPPUNIT_ASSERT(intersections[0].distance == 4.0);
        CPPUNIT_ASSERT(intersections[1].distance == 6.0);

    }


    void TestSphere::testInterspectsSphereATangent() {

        Light::Ray ray(TwoD::Point(0.0f, 1.0f, -5.0f), TwoD::Vector(0.0f, 0.0f, 1.0f));
        Light::Sphere sphere;
        std::vector<Light::Intersection> intersections = sphere.intersect(ray);

        CPPUNIT_ASSERT(intersections.size() == 2);
        CPPUNIT_ASSERT(intersections[0].distance  == 5.0);
        CPPUNIT_ASSERT(intersections[1].distance  == 5.0);
    }

    void TestSphere::testMissSphere() {

        Light::Ray ray(TwoD::Point(0.0f, 2.0f, -5.0f), TwoD::Vector(0.0f, 0.0f, 1.0f));
        Light::Sphere sphere;
        std::vector<Light::Intersection> intersections = sphere.intersect(ray);

        CPPUNIT_ASSERT(intersections.size() == 0);
    }

    void TestSphere::testRayOriginateInside() {

        Light::Ray ray(TwoD::Point(0.0f, 0.0f, 0.0f), TwoD::Vector(0.0f, 0.0f, 1.0f));
        Light::Sphere sphere;
        std::vector<Light::Intersection> intersections = sphere.intersect(ray);

        CPPUNIT_ASSERT(intersections.size() == 2);
        CPPUNIT_ASSERT(intersections[0].distance  == -1.0);
        CPPUNIT_ASSERT(intersections[1].distance  == 1.0);
    }

    void TestSphere::testSphereBehindRay() {

        Light::Ray ray(TwoD::Point(0.0f, 0.0f, 5.0f), TwoD::Vector(0.0f, 0.0f, 1.0f));
        Light::Sphere sphere;
        std::vector<Light::Intersection> intersections = sphere.intersect(ray);

        CPPUNIT_ASSERT(intersections.size() == 2);
        CPPUNIT_ASSERT(intersections[0].distance  == -6.0);
        CPPUNIT_ASSERT(intersections[1].distance  == -4.0);
    }



    void TestSphere::testIntersectSetOfObjects() {

        Light::Ray ray(TwoD::Point(0.0f, 0.0f, 5.0f), TwoD::Vector(0.0f, 0.0f, 1.0f));
        Light::Sphere sphere;
        std::vector<Light::Intersection> intersections = sphere.intersect(ray);


        CPPUNIT_ASSERT(intersections.size() == 2);
        CPPUNIT_ASSERT(*intersections[0].object == sphere);
        CPPUNIT_ASSERT(*intersections[1].object == sphere);
    }

    void TestSphere::testDefaultSphereDefaultTransformation() {

        Light::Sphere sphere;
        CPPUNIT_ASSERT(sphere.transform == TwoD::get_identity_matrix());
    }
}
