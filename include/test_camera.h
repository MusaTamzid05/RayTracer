#ifndef TEST_CAMERA_H
#define TEST_CAMERA_H

#include "test_header.h"

namespace Testing {

    class TestCamera : public  CppUnit::TestFixture {

        CPPUNIT_TEST_SUITE(TestCamera);
        CPPUNIT_TEST(testCameraIntialization);
        CPPUNIT_TEST_SUITE_END();

        public:
            void setUp();
            void tearDown();

        protected:

            void testCameraIntialization();

        private:

    };

};

#endif
