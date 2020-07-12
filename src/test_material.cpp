#include "test_material.h"
#include "material.h"
#include "color.h"

namespace Testing {

    void TestMaterial::setUp() {

    }

    void TestMaterial::tearDown() {

    }

    void TestMaterial::testDefaultMaterial() {
        Light::Material material;
        CPPUNIT_ASSERT(material.color == Engine::Color(1.0f, 1.0f, 1.0f));
        CPPUNIT_ASSERT(material.ambient == 0.1f);
        CPPUNIT_ASSERT(material.diffuse == 0.9f);
        CPPUNIT_ASSERT(material.specular == 0.9f);
        CPPUNIT_ASSERT(material.shininess == 200.0f);

    }
};
