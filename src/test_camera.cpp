#include "test_camera.h"
#include "ray_world.h"
#include "operation.h"
#include "transformation.h"
#include "point.h"
#include "camera.h"
#include "canvas.h"
#include "ray.h"
#include "pixle_data.h"
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


    void TestCamera::testConstructingARayWhenTheCameraIsTransformed() {
        Engine::Camera camera(201, 101, M_PI / 2);
        camera.transform = TwoD::Matrix4x4::rotate_y(M_PI / 4) * TwoD::Matrix4x4::translation(TwoD::Point(0.0f, -2.0f, 5.0f));
        Light::Ray* ray = camera.ray_for_pixel(100.0, 50.0f);
        CPPUNIT_ASSERT(ray->origin == TwoD::Point(0.0f, 2.0f, -5.0f));
        CPPUNIT_ASSERT(ray->direction == TwoD::Vector(sqrt(2) / 2, 0.0f, - sqrt(2) / 2));
    }

    void TestCamera::testRenderingWorldWithCamera() {

        Engine::RayWorld* world = Engine::RayWorld::create_default_world();
        Engine::Camera* camera = new Engine::Camera(11.0f,
                11.0f,
                M_PI / 2
                );

        TwoD::Point from =  TwoD::Point(0.0f, 0.0f, -5.0f);
        TwoD::Point to =  TwoD::Point(0.0f, 0.0f, 0.0f);
        TwoD::Vector up =  TwoD::Vector(0.0f, 1.0f, 0.0f);
        camera->transform = TwoD::Transformation::view_transform(from, to, up);

        Engine::Canvas* image = camera->render(world);
        CPPUNIT_ASSERT(image->pixel_at(5, 5)->color ==  Engine::Color(0.38066f, 0.47583f, 0.2855f));


    }

}
