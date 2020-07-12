#include "test_tuple.h"
#include "operation.h"
#include <iostream>
#include <cmath>

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

    
    void TestTuple::testMulTuple() {
        TwoD::Tuple data(1.0f , -2.0f , 3.0f , -4.0f);
        data *= 3.5f;

        CPPUNIT_ASSERT(data == TwoD::Tuple(3.5f , -7.0f , 10.5f , -14.0f));
    
    }

    void TestTuple::testDevideTuple() {

        TwoD::Tuple data(1.0f , -2.0f , 3.0f , -4.0f);
        data /= 2;
        CPPUNIT_ASSERT(data == TwoD::Tuple(0.5f , -1.0f , 1.5f , -2.0f));
    }

    void TestTuple::testMagnitude() {
    
        TwoD::Tuple data1(0.f , 1.f , 0.f , 0.0f );
        CPPUNIT_ASSERT(Operation::equal(data1.magnitude() , 1.0f));

        TwoD::Tuple data2(0.f , 0.f , 1.f , 0.0f );
        CPPUNIT_ASSERT(Operation::equal(data2.magnitude() , 1.0f));

        TwoD::Tuple data3(1.f , 0.f , 0.f , 0.0f );
        CPPUNIT_ASSERT(Operation::equal(data3.magnitude() , 1.0f));

        TwoD::Tuple data4(1.f , 2.f , 3.f , 0.0f );
        CPPUNIT_ASSERT(Operation::equal(sqrt(14.0f) , data4.magnitude()) == true);
    }
    
    void TestTuple::testNormalize() {

        TwoD::Tuple vec(4.0f , 0.0f , 0.0f , 0.0f);
        CPPUNIT_ASSERT(vec.normalize() == TwoD::Vector(1.0f , 0.0f , 0.0f));

        TwoD::Tuple vec1(1.0f , 2.0f , 3.0f , 0.0f);
        CPPUNIT_ASSERT(vec1.normalize() == TwoD::Vector(0.26726f , 0.53452f , 0.80178f));
    }

    void TestTuple::testDot() {

        TwoD::Vector data1(1.0f , 2.0f , 3.0f);
        TwoD::Vector data2(2.0f , 3.0f , 4.0f);

        CPPUNIT_ASSERT(Operation::equal(data1.dot(data2) , 20.f));
    }

    void TestTuple::testCross() {

        TwoD::Vector a(1.0f , 2.0f , 3.0f);
        TwoD::Vector b(2.0f , 3.0f , 4.0f);

        CPPUNIT_ASSERT(a.cross(b) == TwoD::Vector(-1.0f , 2.0f , -1.0f));
        CPPUNIT_ASSERT(b.cross(a) == TwoD::Vector(1.0f , -2.0f , 1.0f));
    }

    void TestTuple::testReflect() {

        TwoD::Vector vec(1.0f, -1.0f, 0.0f);
        TwoD::Vector nor(0.0f, 1.0f, 0.0f);

        TwoD::Vector result = vec.reflect(nor) ;

        CPPUNIT_ASSERT(result == TwoD::Vector(1.0f, 1.0f,0.0f));


    }

    void TestTuple::testReflectingVectorOffSlanterSurface() {
        
        TwoD::Vector vec(0.0f, -1.0f, 0.0f);
        TwoD::Vector nor(sqrt(2) / 2, sqrt(2) / 2, 0.0f);
        TwoD::Vector result = vec.reflect(nor);
        CPPUNIT_ASSERT(result == TwoD::Vector(1.0f, 0.0f, 0.0f));
    }
};
