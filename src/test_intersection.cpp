#include "test_intersection.h"
#include "sphere.h"
#include "intersection.h"
#include "ray.h"

namespace Testing {

    void TestIntersection::setUp() {

    }

    void TestIntersection::tearDown() {

    }



    void TestIntersection::testIntersectionEncapsulates() {

        Light::Sphere* sphere = new Light::Sphere();
        Light::Intersection intersection(3.5f, sphere);
    
        CPPUNIT_ASSERT(intersection.distance == 3.5f);
        CPPUNIT_ASSERT(intersection.sphere == sphere);
    }

    void TestIntersection::testAggregatingIntersection() {

        Light::Sphere* sphere = new Light::Sphere();
        std::vector<Light::Intersection> intersections;

        intersections.push_back(Light::Intersection(1.0f, sphere));
        intersections.push_back(Light::Intersection(2.0f, sphere));


        CPPUNIT_ASSERT(intersections.size() == 2);
        CPPUNIT_ASSERT(intersections[0].distance == 1.0f);
        CPPUNIT_ASSERT(intersections[1].distance == 2.0f);
    }



};
