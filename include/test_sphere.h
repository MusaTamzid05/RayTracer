#ifndef TEST_SPHERE_H
#define TEST_SPHERE_H

#include "test_header.h"

namespace Testing {

    class TestSphere : public  CppUnit::TestFixture {

        CPPUNIT_TEST_SUITE(TestSphere);
        CPPUNIT_TEST(testInterspectsTwoSphere);
        CPPUNIT_TEST(testInterspectsSphereATangent);
        CPPUNIT_TEST(testMissSphere);
        CPPUNIT_TEST_SUITE_END();

        public:
            void setUp();
            void tearDown();

        protected:

            void testInterspectsTwoSphere();
            void testInterspectsSphereATangent();
            void testMissSphere();

        private:

    };

};

#endif
