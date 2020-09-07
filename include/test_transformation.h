#ifndef TEST_TRANSFORMATION_H
#define TEST_TRANSFORMATION_H


#include "test_header.h"


namespace Testing {

    class TestTransformation : public  CppUnit::TestFixture {

        CPPUNIT_TEST_SUITE(TestTransformation);
        CPPUNIT_TEST(testTransformationMatrixDefaultOrientation);
        CPPUNIT_TEST(testViewTransformationMovesTheWorld);
        CPPUNIT_TEST(testViewTransformationMatrixLookingInPosZDirection);
        CPPUNIT_TEST(testAnArbitaryViewTransformation);
        CPPUNIT_TEST_SUITE_END();

        public:
            void setUp();
            void tearDown();

        protected:

            void testTransformationMatrixDefaultOrientation();
            void testViewTransformationMovesTheWorld();
            void testViewTransformationMatrixLookingInPosZDirection();
            void testAnArbitaryViewTransformation();

    };

};


#endif 
