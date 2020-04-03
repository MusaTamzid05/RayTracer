#ifndef TEST_TUPLE_H
#define TEST_TUPLE_H

#include "test_header.h"
#include "tuple.h"
#include "vector.h"
#include "point.h"

namespace Testing {

    class TestTuple : public  CppUnit::TestFixture {

        CPPUNIT_TEST_SUITE(TestTuple);
        CPPUNIT_TEST(testValidTuple);
        CPPUNIT_TEST(testValidVector);
        CPPUNIT_TEST(testAddTuple);
        CPPUNIT_TEST(testSubTuple);
        CPPUNIT_TEST(testMulTuple);
        CPPUNIT_TEST(testDevideTuple);
        CPPUNIT_TEST(testSubVecFromPoint);
        CPPUNIT_TEST(testNegate);
        CPPUNIT_TEST(testMagnitude);
        CPPUNIT_TEST(testNormalize);
        CPPUNIT_TEST_SUITE_END();

        public:
            void setUp();
            void tearDown();

        protected:

            void testValidTuple();
            void testValidVector();
            void testPointIsTuple();
            void testAddTuple();
            void testSubTuple();
            void testMulTuple();
            void testDevideTuple();
            void testSubVecFromPoint();
            void testNegate();
            void testMagnitude();
            void testNormalize();

        private:
            TwoD::Tuple*  tuple;
            TwoD::Vector* vector;
            TwoD::Point*  point;

    };

};


#endif
