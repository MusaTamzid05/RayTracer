#include "test_camera.h"
#include "operation.h"
#include "point.h"
#include "camera.h"
#include "ray.h"
#include <cmath>

namespace Testing {


    void TestCamera::setUp() {

    }

    void TestCamera::tearDown() {

    }

    void TestCamera::testCameraIntialization() {

        Engine::Camera camera(160, 120, M_PI / 2);
        CPPUNIT_ASSERT(camera.hsize  == 160);
        CPPUNIT_ASSERT(camera.vsize == 120);
        CPPUNIT_ASSERT(Operation::equal(camera.field_of_view, M_PI / 2));
        
    }

    void TestCamera::testPixelSizeHorizontalCanvas() {
        Engine::Camera camera(200, 125, M_PI / 2);
        CPPUNIT_ASSERT(Operation::equal(camera.pixel_size, 0.01f));
    }



    void TestCamera::testPixelSizeVericalCanvas() {
        Engine::Camera camera(125, 200, M_PI / 2);
        CPPUNIT_ASSERT(Operation::equal(camera.pixel_size, 0.01f));
    }


    void TestCamera::testConstructingARayThroughTheCenterOfCanvas() {
        Engine::Camera camera(201, 101, M_PI / 2);
        Light::Ray* ray = camera.ray_for_pixel(100.0, 50.0f);
        CPPUNIT_ASSERT(ray->origin == TwoD::Point(0.0f, 0.0f, 0.0f));
        CPPUNIT_ASSERT(ray->direction == TwoD::Vector(0.0f, 0.0f, -1.0f));
    }


    void TestCamera::testConstructingARayThroughTheCornerOfCanvas() {
        Engine::Camera camera(201, 101, M_PI / 2);
        Light::Ray* ray = camera.ray_for_pixel(0.0, 0.0f);
        CPPUNIT_ASSERT(ray->origin == TwoD::Point(0.0f, 0.0f, 0.0f));
        CPPUNIT_ASSERT(ray->direction == TwoD::Vector(0.66519f, 0.33259f, -0.66851f));
    }

}
