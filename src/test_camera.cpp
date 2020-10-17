#include "test_camera.h"
#include "operation.h"
#include "camera.h"
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

}
