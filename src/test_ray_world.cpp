#include "test_ray_world.h"
#include "ray_world.h"

namespace Testing {

    void TestRayWorld::setUp(){}
    void TestRayWorld::tearDown(){}

    void TestRayWorld::testCreateWorld() {

        Engine::RayWorld* ray_world = new Engine::RayWorld();
        CPPUNIT_ASSERT(ray_world->light == nullptr);
        CPPUNIT_ASSERT(ray_world->objects.size() == 0);
    }
};
