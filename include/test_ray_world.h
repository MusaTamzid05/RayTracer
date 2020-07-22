#ifndef TEST_RAY_WORLD_H
#define TEST_RAY_WORLD_H

#include "test_header.h"

namespace Testing {

    class TestRayWorld : public  CppUnit::TestFixture {

        CPPUNIT_TEST_SUITE(TestRayWorld);
        CPPUNIT_TEST(testCreateWorld);
        CPPUNIT_TEST(testDefaultWorld);
        CPPUNIT_TEST_SUITE_END();

        public:
            void setUp();
            void tearDown();

        protected:

            void testCreateWorld();
            void testDefaultWorld();

        private:

    };

};

#endif
