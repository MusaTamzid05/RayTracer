#ifndef TEST_INTERSECTION_H
#define TEST_INTERSECTION_H

#include "test_header.h"


namespace Testing {

    class TestIntersection : public  CppUnit::TestFixture {

        CPPUNIT_TEST_SUITE(TestIntersection);
        CPPUNIT_TEST(testIntersectionEncapsulates);
        CPPUNIT_TEST(testAggregatingIntersection);
        CPPUNIT_TEST(testHitIntersectionHavePositiveDistance);
        CPPUNIT_TEST_SUITE_END();

        public:
            void setUp();
            void tearDown();

        protected:


            void testIntersectionEncapsulates();
            void testAggregatingIntersection();

            void testHitIntersectionHavePositiveDistance();

        private:

    };

};

#endif
