#include "test_ray.h"
#include "point.h"
#include "vector.h"
#include "ray.h"
#include <iostream>
#include "operation.h"

namespace Testing {

    void TestRay::setUp() {

    }

    void TestRay::tearDown() {

    }

    void TestRay::testCreatingQueryRay() {

        TwoD::Point origin = TwoD::Point(1.0f, 2.0f, 3.0f);
        TwoD::Vector direction = TwoD::Vector(4.0f, 5.0f, 6.0f);

        Light::Ray ray(origin, direction);

        CPPUNIT_ASSERT(ray.origin == origin);
        CPPUNIT_ASSERT(ray.direction == direction);

    }

    void TestRay::testCapturePointFromDistance() {

        TwoD::Point origin = TwoD::Point(2.0f, 3.0f, 4.0f);
        TwoD::Vector direction = TwoD::Vector(1.0f, 0.0f, 0.0f);


        Light::Ray ray(origin, direction);
        CPPUNIT_ASSERT(ray.position(0) == TwoD::Point(2.0f, 3.0f, 4.0f));
        CPPUNIT_ASSERT(ray.position(1) == TwoD::Point(3.0f, 3.0f, 4.0f));
        CPPUNIT_ASSERT(ray.position(-1) == TwoD::Point(1.0f, 3.0f, 4.0f));
        CPPUNIT_ASSERT(ray.position(2.5) == TwoD::Point(4.5f, 3.0f, 4.0f));

    }

};
