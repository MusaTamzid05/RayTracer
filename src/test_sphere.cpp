#include "test_sphere.h"
#include "ray.h"
#include "point.h"
#include "vector.h"
#include "sphere.h"
#include <iostream>

namespace Testing {

    void TestSphere::setUp() {

    }

    void TestSphere::tearDown() {

    }

    void TestSphere::testInterspectsTwoSphere() {

        Light::Ray ray(TwoD::Point(0.0f, 0.0f, -5.0f), TwoD::Vector(0.0f, 0.0f, 1.0f));
        Light::Sphere sphere;

        std::vector<float> interspect_points = sphere.intersect(ray);

        CPPUNIT_ASSERT(interspect_points.size() == 2);
        CPPUNIT_ASSERT(interspect_points[0] == 4.0);
        CPPUNIT_ASSERT(interspect_points[1] == 6.0);

    }


    void TestSphere::testInterspectsSphereATangent() {

        Light::Ray ray(TwoD::Point(0.0f, 1.0f, -5.0f), TwoD::Vector(0.0f, 0.0f, 1.0f));
        Light::Sphere sphere;
        std::vector<float> interspect_points = sphere.intersect(ray);

        CPPUNIT_ASSERT(interspect_points.size() == 2);
        CPPUNIT_ASSERT(interspect_points[0] == 5.0);
        CPPUNIT_ASSERT(interspect_points[1] == 5.0);
    }

    void TestSphere::testMissSphere() {

        Light::Ray ray(TwoD::Point(0.0f, 2.0f, -5.0f), TwoD::Vector(0.0f, 0.0f, 1.0f));
        Light::Sphere sphere;
        std::vector<float> interspect_points = sphere.intersect(ray);

        CPPUNIT_ASSERT(interspect_points.size() == 0);
    }

    void TestSphere::testRayOriginateInside() {

        Light::Ray ray(TwoD::Point(0.0f, 0.0f, 0.0f), TwoD::Vector(0.0f, 0.0f, 1.0f));
        Light::Sphere sphere;
        std::vector<float> interspect_points = sphere.intersect(ray);

        CPPUNIT_ASSERT(interspect_points.size() == 2);
        CPPUNIT_ASSERT(interspect_points[0] == -1.0);
        CPPUNIT_ASSERT(interspect_points[1] == 1.0);
    }
}
