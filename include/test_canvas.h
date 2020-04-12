#ifndef TEST_CANVAS_H
#define TEST_CANVAS_H

#include "test_header.h"


namespace Testing {

    class TestCanvas : public  CppUnit::TestFixture {

        CPPUNIT_TEST_SUITE(TestCanvas);
        CPPUNIT_TEST(testCanvasIsBlackAtInit);
        CPPUNIT_TEST(testPPMHeader);
        CPPUNIT_TEST_SUITE_END();

        public:
            void setUp();
            void tearDown();

        protected:

            void testCanvasIsBlackAtInit();
            void testPPMHeader();

        private:

    };

};

#endif
