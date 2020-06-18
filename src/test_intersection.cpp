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
        CPPUNIT_ASSERT(intersection.object == sphere);
    }

    void TestIntersection::testAggregatingIntersection() {

        Light::Sphere* sphere = new Light::Sphere();
        Light::IntersectionContainer container;

        container.add(Light::Intersection(1.0f, sphere));
        container.add(Light::Intersection(2.0f, sphere));


        CPPUNIT_ASSERT(container.size() == 2);
        CPPUNIT_ASSERT(container.get(0).distance == 1.0f);
        CPPUNIT_ASSERT(container.get(1).distance == 2.0f);
    }

    void TestIntersection::testHitIntersectionHavePositiveDistance() {

        Light::Sphere* sphere = new Light::Sphere();
        Light::IntersectionContainer container;

        container.add(Light::Intersection(1.0f, sphere));
        container.add(Light::Intersection(2.0f, sphere));

        Light::Intersection intersection = container.hit();

        CPPUNIT_ASSERT(intersection.distance  == 1.0f);

    }


};
