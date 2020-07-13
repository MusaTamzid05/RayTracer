#ifndef TEST_MATERIAL_H
#define TEST_MATERIAL_H

#include "test_header.h"

namespace Testing {

    class TestMaterial: public  CppUnit::TestFixture {

        CPPUNIT_TEST_SUITE(TestMaterial);
        CPPUNIT_TEST(testDefaultMaterial);
        CPPUNIT_TEST(testLightingWithEyeBetweenLightAndSurface);
        CPPUNIT_TEST(testLightingWithEyeBetweenLightAndSurface45);
        CPPUNIT_TEST_SUITE_END();

        public:
            void setUp();
            void tearDown();

        protected:

            void testDefaultMaterial();
            void testLightingWithEyeBetweenLightAndSurface();
            void testLightingWithEyeBetweenLightAndSurface45();

        private:

    };

};

#endif
