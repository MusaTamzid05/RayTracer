#include "test_sphere.h"
#include "ray.h"
#include "point.h"
#include "vector.h"
#include "sphere.h"
#include "intersection.h"
#include <iostream>
#include <math.h>

namespace Testing {

    void TestSphere::setUp() {

    }

    void TestSphere::tearDown() {

    }

    void TestSphere::testInterspectsTwoSphere() {

        Light::Ray ray(TwoD::Point(0.0f, 0.0f, -5.0f), TwoD::Vector(0.0f, 0.0f, 1.0f));
        Light::Sphere sphere;

        Light::IntersectionContainer intersections = sphere.intersect(ray);

        CPPUNIT_ASSERT(intersections.size() == 2);
        CPPUNIT_ASSERT(intersections.get(0).distance == 4.0f);
        CPPUNIT_ASSERT(intersections.get(1).distance == 6.0f);

    }


    void TestSphere::testInterspectsSphereATangent() {

        Light::Ray ray(TwoD::Point(0.0f, 1.0f, -5.0f), TwoD::Vector(0.0f, 0.0f, 1.0f));
        Light::Sphere sphere;
        Light::IntersectionContainer intersections = sphere.intersect(ray);

        CPPUNIT_ASSERT(intersections.size() == 2);
        CPPUNIT_ASSERT(intersections.get(0).distance == 5.0f);
        CPPUNIT_ASSERT(intersections.get(1).distance == 5.0f);
    }

    void TestSphere::testMissSphere() {

        Light::Ray ray(TwoD::Point(0.0f, 2.0f, -5.0f), TwoD::Vector(0.0f, 0.0f, 1.0f));
        Light::Sphere sphere;
        Light::IntersectionContainer intersections = sphere.intersect(ray);

        CPPUNIT_ASSERT(intersections.size() == 0);
    }

    void TestSphere::testRayOriginateInside() {

        Light::Ray ray(TwoD::Point(0.0f, 0.0f, 0.0f), TwoD::Vector(0.0f, 0.0f, 1.0f));
        Light::Sphere sphere;
        Light::IntersectionContainer intersections = sphere.intersect(ray);

        CPPUNIT_ASSERT(intersections.size() == 2);
        CPPUNIT_ASSERT(intersections.get(0).distance == -1.0f);
        CPPUNIT_ASSERT(intersections.get(1).distance == 1.0f);
    }

    void TestSphere::testSphereBehindRay() {

        Light::Ray ray(TwoD::Point(0.0f, 0.0f, 5.0f), TwoD::Vector(0.0f, 0.0f, 1.0f));
        Light::Sphere sphere;
        Light::IntersectionContainer intersections = sphere.intersect(ray);

        CPPUNIT_ASSERT(intersections.size() == 2);
        CPPUNIT_ASSERT(intersections.get(0).distance == -6.0f);
        CPPUNIT_ASSERT(intersections.get(1).distance == -4.0f);
    }



    void TestSphere::testIntersectSetOfObjects() {

        Light::Ray ray(TwoD::Point(0.0f, 0.0f, 5.0f), TwoD::Vector(0.0f, 0.0f, 1.0f));
        Light::Sphere sphere;
        Light::IntersectionContainer intersections = sphere.intersect(ray);


        CPPUNIT_ASSERT(intersections.size() == 2);
        CPPUNIT_ASSERT(*intersections.get(0).object == sphere);
        CPPUNIT_ASSERT(*intersections.get(1).object == sphere);
    }

    void TestSphere::testDefaultSphereDefaultTransformation() {

        Light::Sphere sphere;
        CPPUNIT_ASSERT(sphere.get_transform()== TwoD::get_identity_matrix());
    }

    void TestSphere::testChangingSphereTransformation() {

        Light::Sphere sphere;
        TwoD::Matrix4x4 tranfomation = TwoD::Matrix4x4::translation(TwoD::Point(2.0f, 3.0f, 4.0f));
        sphere.set_transform(tranfomation);

        CPPUNIT_ASSERT(sphere.get_transform() == tranfomation);
    }

    void TestSphere::testIntersectingAScaledSphereWithRay() {

        Light::Ray ray(TwoD::Point(0.0f, 0.0f, -5.0f), TwoD::Vector(0.0f, 0.0f, 1.0f));
        Light::Sphere sphere;
        sphere.set_transform(TwoD::Matrix4x4::scale(TwoD::Point(2.0f, 2.0f, 2.0f)));

        Light::IntersectionContainer intersections = sphere.intersect(ray);

        CPPUNIT_ASSERT(intersections.size() == 2);
        CPPUNIT_ASSERT(intersections.get(0).distance == 3.0f);
        CPPUNIT_ASSERT(intersections.get(1).distance == 7.0f);

    }


    void TestSphere::testIntersecTranslatedSphereWithRay() {

        Light::Ray ray(TwoD::Point(0.0f, 0.0f, -5.0f), TwoD::Vector(0.0f, 0.0f, 1.0f));
        Light::Sphere sphere;

        sphere.set_transform(TwoD::Matrix4x4::translation(TwoD::Point(5.0f, 0.0f, 0.0f)));
        Light::IntersectionContainer  intersections = sphere.intersect(ray);

        CPPUNIT_ASSERT(intersections.size() == 0);
    }


    void TestSphere::testNormalSphereAtAPointXAxis() {

        Light::Sphere* sphere = new Light::Sphere();
        TwoD::Vector vector_normal = sphere->normal_at(TwoD::Point(1.0f, 0.0f, 0.0f));

        CPPUNIT_ASSERT(vector_normal == TwoD::Vector(1.0f, 0.0f, 0.0f));

    }

    void TestSphere::testNormalSphereAtAPointYAxis() {

        Light::Sphere* sphere = new Light::Sphere();
        TwoD::Vector vector_normal = sphere->normal_at(TwoD::Point(0.0f, 1.0f, 0.0f));

        CPPUNIT_ASSERT(vector_normal == TwoD::Vector(0.0f, 1.0f, 0.0f));

    }


    void TestSphere::testNormalSphereAtAPointZAxis() {

        Light::Sphere* sphere = new Light::Sphere();
        TwoD::Vector vector_normal = sphere->normal_at(TwoD::Point(0.0f, 0.0f, 1.0f));

        CPPUNIT_ASSERT(vector_normal == TwoD::Vector(0.0f, 0.0f, 1.0f));

    }


    void TestSphere::testSphereNormalAtNonAxialPoint() {

        float val = sqrt(3) / 3;


        Light::Sphere* sphere = new Light::Sphere();
        TwoD::Vector vector_normal = sphere->normal_at(TwoD::Point(val, val, val));

        CPPUNIT_ASSERT(vector_normal == TwoD::Vector(val, val, val));

    }
}
