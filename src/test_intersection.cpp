#include "test_intersection.h"
#include "sphere.h"
#include "intersection.h"

namespace Testing {

    void TestIntersection::setUp() {

    }

    void TestIntersection::tearDown() {

    }



    void TestIntersection::testIntersectionEncapsulates() {

        Light::Sphere* sphere = new Light::Sphere();
        Light::Intersection intersection(3.5f, sphere);
    
        CPPUNIT_ASSERT(intersection.distance  == 3.5f);
        CPPUNIT_ASSERT(intersection.sphere == sphere);
    }

};
