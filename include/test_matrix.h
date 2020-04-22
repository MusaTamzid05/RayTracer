#ifndef TEST_MATRIX_H
#define TEST_MATRIX_H


#include "test_header.h"

namespace Testing {

    class TestMatrix : public CppUnit::TestFixture {

        CPPUNIT_TEST_SUITE(TestMatrix);
        CPPUNIT_TEST(testMatrixConstruction);
        CPPUNIT_TEST_SUITE_END();

        public:
            void setUp();
            void tearDown();

        protected:

            void testMatrixConstruction();

        private:

    };

};

#endif
