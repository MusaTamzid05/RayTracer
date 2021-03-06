#ifndef TEST_CAMERA_H
#define TEST_CAMERA_H

#include "test_header.h"

namespace Testing {

    class TestCamera : public  CppUnit::TestFixture {

        CPPUNIT_TEST_SUITE(TestCamera);
        CPPUNIT_TEST(testCameraIntialization);
        CPPUNIT_TEST(testPixelSizeHorizontalCanvas);
        CPPUNIT_TEST(testPixelSizeVericalCanvas);
        CPPUNIT_TEST(testConstructingARayThroughTheCenterOfCanvas);
        CPPUNIT_TEST(testConstructingARayThroughTheCornerOfCanvas);
        CPPUNIT_TEST(testConstructingARayWhenTheCameraIsTransformed);
        CPPUNIT_TEST(testRenderingWorldWithCamera);
        CPPUNIT_TEST_SUITE_END();

        public:
            void setUp();
            void tearDown();

        protected:

            void testCameraIntialization();
            void testPixelSizeHorizontalCanvas();
            void testPixelSizeVericalCanvas();
            void testConstructingARayThroughTheCenterOfCanvas();
            void testConstructingARayThroughTheCornerOfCanvas();
            void testConstructingARayWhenTheCameraIsTransformed();
            void testRenderingWorldWithCamera();

        private:

    };

};

#endif
