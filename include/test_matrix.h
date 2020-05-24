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
        CPPUNIT_TEST(testMinor);
        CPPUNIT_TEST(testCofactor);
        CPPUNIT_TEST(testInvertibleMatrix);
        CPPUNIT_TEST(testInverseMatrix);
        CPPUNIT_TEST(testMultiplyInverse);
        CPPUNIT_TEST(testTranslationMatrix);
        CPPUNIT_TEST(testInverseTranslationMatrix);
        CPPUNIT_TEST(testTranslationWithVector);
        CPPUNIT_TEST(testScaleMatrix);
        CPPUNIT_TEST(testScaleMatrixVector);
        CPPUNIT_TEST(testReflection);
        CPPUNIT_TEST(testRotateMatrixXAxis);
        CPPUNIT_TEST(testRotateMatrixYAxis);
        CPPUNIT_TEST(testRotateMatrixZAxis);
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
            void testMinor();
            void testCofactor();
            void testInvertibleMatrix();
            void testInverseMatrix();
            void testMultiplyInverse();

            void testTranslationMatrix();
            void testInverseTranslationMatrix();
            void testTranslationWithVector();

            void testScaleMatrix();
            void testScaleMatrixVector();
            void testReflection();
            void testRotateMatrixXAxis();
            void testRotateMatrixYAxis();
            void testRotateMatrixZAxis();

        private:

    };

};

#endif
