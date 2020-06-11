#ifndef TEST_RAY_H
#define TEST_RAY_H

#include "test_header.h"


namespace Testing {

    class TestRay : public  CppUnit::TestFixture {

        CPPUNIT_TEST_SUITE(TestRay);
        CPPUNIT_TEST(testCreatingQueryRay);
        CPPUNIT_TEST(testCapturePointFromDistance);
        CPPUNIT_TEST_SUITE_END();

        public:
            void setUp();
            void tearDown();

        protected:

            void testCreatingQueryRay();
            void testCapturePointFromDistance();

    };

};

#endif
