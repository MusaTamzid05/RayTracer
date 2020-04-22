#ifndef TEST_CANVAS_H
#define TEST_CANVAS_H

#include "test_header.h"

namespace Testing {

    class TestCanvas : public  CppUnit::TestFixture {

        CPPUNIT_TEST_SUITE(TestCanvas);
        CPPUNIT_TEST(testPPMHeader);
        CPPUNIT_TEST(testPPMData);
        CPPUNIT_TEST_SUITE_END();

        public:
            void setUp();
            void tearDown();

        protected:

            void testPPMHeader();
            void testPPMData();

        private:

    };

};


#endif
