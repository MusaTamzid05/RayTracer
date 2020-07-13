#include "test_material.h"
#include "material.h"
#include "color.h"
#include "point.h"
#include "vector.h"
#include "point_light.h"

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

    void TestMaterial::testLightingWithEyeBetweenLightAndSurface() {
        
        Light::Material material;
        TwoD::Point position(0.0f, 0.0f, 0.0f);

        TwoD::Vector eye_vector = TwoD::Vector(0.0f, 0.0f, -1.0f);
        TwoD::Vector normal_vector = TwoD::Vector(0.0f, 0.0f, -1.0f);
        Light::PointLight point_light = Light::PointLight(new Engine::Color(1.0f, 1.0f, 1.0f),
                 new TwoD::Point(0.0f, 0.0f, -10.0f));

        TwoD::Vector result = material.lighting(&point_light, position,  eye_vector, normal_vector);
        CPPUNIT_ASSERT(result == TwoD::Vector(1.9f, 1.9f, 1.9f));


    }
};
