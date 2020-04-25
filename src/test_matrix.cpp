#include "test_matrix.h"
#include "matrix.h"

namespace Testing {


    void TestMatrix::setUp() {

    }

    void TestMatrix::tearDown() {

    }

    void TestMatrix::testMatrixConstruction() {

        float arr4x4[4][4] = {
            {1.0f , 2.0f , 3.0f, 4.0f},
            {5.5f , 6.5f , 7.5f , 8.5f },
            {9.0f , 10.0f , 11.0f , 12.0f},
            {13.5f , 14.5f , 15.5f ,  16.5f}
        };


        TwoD::Matrix4x4 matrix4x4(arr4x4);

        CPPUNIT_ASSERT(matrix4x4.get(0,0) == 1.0f);
        CPPUNIT_ASSERT(matrix4x4.get(0,3) == 4.0f);
        CPPUNIT_ASSERT(matrix4x4.get(1,0) == 5.5f);
        CPPUNIT_ASSERT(matrix4x4.get(1,2) == 7.5f);
        CPPUNIT_ASSERT(matrix4x4.get(2,2) == 11.0f);
        CPPUNIT_ASSERT(matrix4x4.get(3,0) == 13.5f);
        CPPUNIT_ASSERT(matrix4x4.get(3,2) == 15.5f);


        float arr3x3[3][3] = {
            {-3.0f , 5.0f , 0.0f},
            {1.0f , -2.0f , -7.0f},
            {0.0f , 1.0f , 1.0f }
        };


        TwoD::Matrix3x3 matrix3x3(arr3x3);

        CPPUNIT_ASSERT(matrix3x3.get(0,0) == -3.0f);
        CPPUNIT_ASSERT(matrix3x3.get(1,1) == -2.0f);
        CPPUNIT_ASSERT(matrix3x3.get(2,2) == 1.0f);


        float arr2x2[2][2] = {
            {-3.0f , 5.0f },
            {1.0f , -2.0f }
        };


        TwoD::Matrix2x2 matrix2x2(arr2x2);

        CPPUNIT_ASSERT(matrix2x2.get(0,0) == -3.0f);
        CPPUNIT_ASSERT(matrix2x2.get(1,1) == -2.0f);
    }

    void TestMatrix::testMatrixEqualation() {


        float a[4][4] = {
            {1.0f , 2.0f , 3.0f, 4.0f},
            {5.0f , 6.0f , 7.0f , 8.0f },
            {9.0f , 10.0f , 11.0f , 12.0f},
            {13.0f , 14.0f , 15.0f ,  16.0f}
        };


        float b[4][4] = {
            {1.0f , 2.0f , 3.0f, 4.0f},
            {5.0f , 6.0f , 7.0f , 8.0f },
            {9.0f , 10.0f , 11.0f , 12.0f},
            {13.0f , 14.0f , 15.0f ,  16.0f}
        };


        
        TwoD::Matrix4x4 a_(a);
        TwoD::Matrix4x4 b_(b);

        CPPUNIT_ASSERT(a_ == b_);

        b_.set(2 , 1 , 5.0);

        CPPUNIT_ASSERT(a_ != b_);
    }


    void TestMatrix::testMatrixMultiplication() {


        float a[4][4] = {
            {1.0f , 2.0f , 3.0f, 4.0f},
            {5.0f , 6.0f , 7.0f , 8.0f },
            {9.0f , 8.0f , 7.0f , 6.0f},
            {5.0f , 4.0f , 3.0f ,  2.0f}
        };


        float b[4][4] = {
            {-2.0f , 1.0f , 2.0f, 3.0f},
            {3.0f , 2.0f , 1.0f , -1.0f },
            {4.0f , 3.0f , 6.0f , 5.0f},
            {1.0f , 2.0f , 7.0f ,  8.0f}
        };


        float c[4][4] = {
            {20.0f , 22.0f , 50.0f, 48.0f},
            {44.0f , 54.0f , 114.0f , 108.0f },
            {40.0f , 58.0f , 110.0f , 102.0f},
            {16.0f , 26.0f , 46.0f ,  42.0f}
        };


        TwoD::Matrix4x4 a_(a);
        TwoD::Matrix4x4 b_(b);
        TwoD::Matrix4x4 c_(c);

        TwoD::Matrix result = a_* b_;
        CPPUNIT_ASSERT(result == c_);
    }
}
