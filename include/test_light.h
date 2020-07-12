#ifndef TEST_LIGHT_H
#define TEST_LIGHT_H


#include "test_header.h"


namespace Testing {

    class TestLight : public  CppUnit::TestFixture {

        CPPUNIT_TEST_SUITE(TestLight);
        CPPUNIT_TEST(testPointLightPositionAndIntensity);
        CPPUNIT_TEST_SUITE_END();

        public:
            void setUp();
            void tearDown();

            void testPointLightPositionAndIntensity();

        protected:

        private:

    };

};

#endif
