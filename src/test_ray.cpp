#include "test_ray.h"
#include "point.h"
#include "vector.h"
#include "ray.h"

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
};
