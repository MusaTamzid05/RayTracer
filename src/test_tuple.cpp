#include "test_tuple.h"
#include "equal.h"

namespace Testing {


    void TestTuple::setUp() {
        tuple = new TwoD::Tuple(4.3f , - 4.2f , 3.1f , 1.0f);
        vector = new TwoD::Vector(4.3f , - 4.2f , 3.1f);
    }

    void TestTuple::tearDown() {
        delete tuple;
        delete vector;
    }

    void TestTuple::testValidTuple() {
        CPPUNIT_ASSERT(Operation::equal(tuple->w , 1.0f) ==  true);
    }

    void TestTuple::testValidVector() {
        CPPUNIT_ASSERT(Operation::equal(vector->w , 0.0f) ==  true);
    }


    void TestTuple::testPointIsTuple() {

        TwoD::Tuple* temp_tuple =  new TwoD::Tuple(4.3f , - 4.2f , 3.1f , 1.0f);
        TwoD::Point* temp_point =  new TwoD::Point(4.3f , - 4.2f , 3.1f);

        CPPUNIT_ASSERT(Operation::equal(temp_tuple->x   , temp_point->x) ==  true);
        CPPUNIT_ASSERT(Operation::equal(temp_tuple->y   , temp_point->y) ==  true);
        CPPUNIT_ASSERT(Operation::equal(temp_tuple->z   , temp_point->z) ==  true);
        CPPUNIT_ASSERT(Operation::equal(temp_tuple->w   , temp_point->z) ==  true);
    }
    
    void TestTuple::testAddTuple() {
        
        TwoD::Tuple* data1 = new TwoD::Tuple(3 , -2 , 5, 1);
        TwoD::Tuple* data2 = new TwoD::Tuple(-2 , 3 , 1, 0);
        TwoD::Tuple* result  = new TwoD::Tuple(1 , 1 , 6, 1);
        CPPUNIT_ASSERT((*data1 + *data2) ==  *result);

    }


    void TestTuple::testSubTuple() {
        
        TwoD::Tuple* data1 = new TwoD::Tuple(1.0f , 3.0f , 1.0f , 1.0f);
        TwoD::Tuple* data2 = new TwoD::Tuple(1.0f , 1.0f , 1.0f , 1.0f);
        TwoD::Tuple* result  = new TwoD::Tuple(0.0f , 2.0f , 0.0f, 0.0f);
        CPPUNIT_ASSERT((*data1 - *data2)==  *result);

    }

    void TestTuple::testSubVecFromPoint() {

        TwoD::Point* point = new TwoD::Point(5.0f , 4.0f , 3.0f);
        TwoD::Vector* vector = new TwoD::Vector(3.0f , 1.0f , 2.0f);
        TwoD::Point* result  = new TwoD::Point(2.0f , 3.0f , 1.0f);
        CPPUNIT_ASSERT((*point - *vector) ==  *result);
    }

    void TestTuple::testNegate() {
        
        TwoD::Vector vec = TwoD::Vector(1.0f , -2.0f , 3.0f);
        CPPUNIT_ASSERT(vec.negate() == TwoD::Vector(-1.0f , 2.0f , -3.0f));
    }
};
