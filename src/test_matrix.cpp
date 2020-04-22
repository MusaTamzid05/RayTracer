#include "test_matrix.h"
#include "matrix.h"

namespace Testing {


    void TestMatrix::setUp() {

    }

    void TestMatrix::tearDown() {

    }

    void TestMatrix::testMatrixConstruction() {

        float arr[4][4] = {
            {1.0f , 2.0f , 3.0f, 4.0f},
            {5.5f , 6.5f , 7.5f , 8.5f },
            {9.0f , 10.0f , 11.0f , 12.0f},
            {13.5f , 14.5f , 15.5f ,  16.5f}
        };


        TwoD::Matrix4x4 matrix(arr);

        CPPUNIT_ASSERT(matrix.get(0,0) == 1.0f);
        CPPUNIT_ASSERT(matrix.get(0,3) == 4.0f);
        CPPUNIT_ASSERT(matrix.get(1,0) == 5.5f);
        CPPUNIT_ASSERT(matrix.get(1,2) == 7.5f);
        CPPUNIT_ASSERT(matrix.get(2,2) == 11.0f);
        CPPUNIT_ASSERT(matrix.get(3,0) == 13.5f);
        CPPUNIT_ASSERT(matrix.get(3,2) == 15.5f);

    }

}
