#include "test_light.h"
#include "point_light.h"
#include "point.h"
#include "color.h"

namespace Testing {

    void TestLight::setUp() {

    }


    void TestLight::tearDown() {

    }

    void TestLight::testPointLightPositionAndIntensity() {

        Light::PointLight point_light;
        Engine::Color* color = new Engine::Color(1.0f, 1.0f, 1.0f);
        TwoD::Point* position = new TwoD::Point(0.0f, 0.0f, 0.0f);

        point_light.position = position;
        point_light.color = color;
        CPPUNIT_ASSERT(point_light.position == position);
        CPPUNIT_ASSERT(point_light.color == color);

    }

};
