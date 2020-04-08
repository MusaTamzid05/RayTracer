#ifndef TEST_COLOR_H
#define TEST_COLOR_H

#include "test_header.h"


namespace Testing {

    class TestColor : public  CppUnit::TestFixture {

        CPPUNIT_TEST_SUITE(TestColor);
        CPPUNIT_TEST(testColorIsTuple);
        CPPUNIT_TEST(testAddColor);
        CPPUNIT_TEST_SUITE_END();

        public:
            void setUp();
            void tearDown();

        protected:

            void testColorIsTuple();
            void testAddColor();

        private:

    };

};

#endif
