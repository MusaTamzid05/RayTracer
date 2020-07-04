#ifndef TEST_SPHERE_H
#define TEST_SPHERE_H

#include "test_header.h"

namespace Testing {

    class TestSphere : public  CppUnit::TestFixture {

        CPPUNIT_TEST_SUITE(TestSphere);
        CPPUNIT_TEST(testInterspectsTwoSphere);
        CPPUNIT_TEST(testInterspectsSphereATangent);
        CPPUNIT_TEST(testMissSphere);
        CPPUNIT_TEST(testRayOriginateInside);
        CPPUNIT_TEST(testSphereBehindRay);
        CPPUNIT_TEST(testIntersectSetOfObjects);
        CPPUNIT_TEST(testDefaultSphereDefaultTransformation);
        CPPUNIT_TEST(testChangingSphereTransformation);
        CPPUNIT_TEST(testIntersectingAScaledSphereWithRay);
        CPPUNIT_TEST(testIntersecTranslatedSphereWithRay);
        CPPUNIT_TEST(testNormalSphereAtAPointXAxis);
        CPPUNIT_TEST(testNormalSphereAtAPointYAxis);
        CPPUNIT_TEST(testNormalSphereAtAPointZAxis);
        CPPUNIT_TEST(testSphereNormalAtNonAxialPoint);
        CPPUNIT_TEST_SUITE_END();

        public:
            void setUp();
            void tearDown();

        protected:

            void testInterspectsTwoSphere();
            void testInterspectsSphereATangent();
            void testMissSphere();
            void testRayOriginateInside();
            void testSphereBehindRay();


            void testIntersectSetOfObjects();

            void testDefaultSphereDefaultTransformation();
            void testChangingSphereTransformation();

            void testIntersectingAScaledSphereWithRay();
            void testIntersecTranslatedSphereWithRay();

            void testNormalSphereAtAPointXAxis();
            void testNormalSphereAtAPointYAxis();
            void testNormalSphereAtAPointZAxis();


            void testSphereNormalAtNonAxialPoint();

        private:

    };

};

#endif
