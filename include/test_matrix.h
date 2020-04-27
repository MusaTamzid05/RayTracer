#ifndef TEST_MATRIX_H
#define TEST_MATRIX_H


#include "test_header.h"

namespace Testing {

    class TestMatrix : public CppUnit::TestFixture {

        CPPUNIT_TEST_SUITE(TestMatrix);
        CPPUNIT_TEST(testMatrixConstruction);
        CPPUNIT_TEST(testMatrixEqualation);
        CPPUNIT_TEST(testMatrixMultiplication);
        CPPUNIT_TEST(testMatrixTupleMultiplication);
        CPPUNIT_TEST(testIdentityMatrix);
        CPPUNIT_TEST(testTransposeMatrix);
        CPPUNIT_TEST(testTransposeMatrixIdentity);
        CPPUNIT_TEST(testDeterminate);
        CPPUNIT_TEST(testSubMatrix);
        CPPUNIT_TEST_SUITE_END();

        public:
            void setUp();
            void tearDown();

        protected:

            void testMatrixConstruction();
            void testMatrixEqualation();
            void testMatrixMultiplication();
            void testMatrixTupleMultiplication();
            void testIdentityMatrix();
            void testTransposeMatrix();
            void testTransposeMatrixIdentity();
            void testDeterminate();
            void testSubMatrix();

        private:

    };

};

#endif
