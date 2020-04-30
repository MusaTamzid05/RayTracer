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

    void TestMatrix::testMatrixTupleMultiplication() {


        float a[4][4] = {
            {1.0f , 2.0f , 3.0f, 4.0f},
            {2.0f , 4.0f , 4.0f , 2.0f },
            {8.0f , 6.0f , 4.0f , 1.0f},
            {0.0f , 0.0f , 0.0f ,  1.0f}
        };

        TwoD::Matrix4x4 a_(a);
        TwoD::Tuple tuple(1.0f , 2.0f , 3.0f , 1.0f);
        TwoD::Tuple result = a_ * tuple;
        CPPUNIT_ASSERT(result == TwoD::Tuple(18.0f , 24.0f , 33.0f , 1.0f));
    }

    void TestMatrix::testIdentityMatrix() {
        
        float arr[4][4] = {
            {0.0f , 1.0f , 2.0f , 4.0f},
            {0.0f , 1.0f , 4.0f , 8.0f},
            {2.0f , 4.0f , 8.0f , 16.0f},
            {4.0f , 8.0f , 16.0f , 32.0f}
        };

        TwoD::Matrix4x4 a(arr);
        CPPUNIT_ASSERT(a * TwoD::get_identity_matrix() == a);

    }

    
    void TestMatrix::testTransposeMatrix() {

        float arr1[4][4] = {
            {0.0f , 9.0f , 3.0f , 0.0f},
            {9.0f , 8.0f , 0.0f , 8.0f},
            {1.0f , 8.0f , 5.0f , 3.0f},
            {0.0f , 0.0f , 5.0f , 8.0f}
        };


        float arr2[4][4] = {
            {0.0f , 9.0f , 1.0f , 0.0f},
            {9.0f , 8.0f , 8.0f , 0.0f},
            {3.0f , 0.0f , 5.0f , 5.0f},
            {0.0f , 8.0f , 3.0f , 8.0f}
        };

        TwoD::Matrix4x4 a(arr1);
        TwoD::Matrix4x4 b(arr2);
        CPPUNIT_ASSERT(a.transpose()  == b);
    }

    void TestMatrix::testTransposeMatrixIdentity() {

        TwoD::Matrix matrix = TwoD::get_identity_matrix();
        CPPUNIT_ASSERT(matrix.transpose()  == matrix);
    }

    void TestMatrix::testDeterminate() {
        
        float arr[2][2] = {
            {1.0f , 5.0f},
            {-3.0f , 2.0f}
        };

        TwoD::Matrix2x2 matrix(arr);
        float currentDetermind = matrix.determinate();
        CPPUNIT_ASSERT(currentDetermind  == 17.0f);
    }

    void TestMatrix::testSubMatrix() {

        float arr[3][3] = {
            {1.0f , 5.0f , 0.0f},
            {-3.0f , 2.0f , 7.0f},
            {0.0f , 6.0f , -3.0f}
        };

        float b[2][2] = {
            {-3.0f , 2.0f},
            {0.0f , 6.0f}
        };


        TwoD::Matrix3x3 matrix(arr);
        TwoD::Matrix2x2 matrix_b(b);
        TwoD::Matrix result = matrix.sub_matrix(0 , 2);

        CPPUNIT_ASSERT(result == matrix_b);


        float arr_c[4][4] = {

            {-6.0f , 1.0f , 1.0f , 6.0f},
            {-8.0f , 5.0f , 8.0f , 6.0f},
            {-1.0f , 0.0f , 8.0f , 2.0f},
            {-7.0f , 1.0f , -1.0f , 1.0f}
        };

        float d[3][3] =  {
            {-6.0f , 1.0f , 6.0f},
            {-8.0f , 8.0f , 6.0f},
            {-7.0f , -1.0f , 1.0f}
        };


        TwoD::Matrix4x4 matrix_c(arr_c);
        TwoD::Matrix3x3 matrix_d(d);
        TwoD::Matrix result2 = matrix_c.sub_matrix(2 , 1);

        CPPUNIT_ASSERT(matrix_d == result2);

    }


    void TestMatrix::testMinor() {

        float arr[3][3] = {
            {3.0f , 5.0f , 0.0f},
            {2.0f , -1.0f , -7.0f},
            {6.0f , -1.0f , 5.0f}
        };

        TwoD::Matrix3x3 matrix(arr);
        TwoD::Matrix result1 = matrix.sub_matrix(1 , 0);
        CPPUNIT_ASSERT(result1.determinate() == matrix.minor_(1 , 0));
    }


    
    void TestMatrix::testCofactor() {

        float arr[3][3] = {
            {1.0f , 2.0f , 6.0f},
            {-5.0f , 8.0f , -4.0f},
            {2.0f , 6.0f , 4.0f}
        };

        TwoD::Matrix3x3 matrix(arr);
        CPPUNIT_ASSERT(matrix.cofactor(0,0) == 56.0f);
        CPPUNIT_ASSERT(matrix.cofactor(0,1) == 12.0f);
        CPPUNIT_ASSERT(matrix.cofactor(0,2) == -46.0f);
        CPPUNIT_ASSERT(matrix.determinate()  == -196.0f);
    }


    
    void TestMatrix::testInvertibleMatrix() {

        float arr[4][4] = {
            {6.0 , 4.0f , 4.0f , 4.0f},
            {5.0 , 5.0f , 7.0f , 6.0f},
            {4.0 , -9.0f , 3.0f , -7.0f},
            {9.0 , 1.0f , 7.0f , -6.0f}
        };

        TwoD::Matrix4x4 a(arr);
        CPPUNIT_ASSERT(a.is_invertible() == true);

        /*
         * This array will be used for the next test.
         * not removing this because i dont want to
         * type it again !! :<
        float arr2[4][4]= {
            {-5.0 , 2.0f , 6.0f , -8.0f},
            {1.0 , -5.0f , 1.0f , 8.0f},
            {7.0 , 7.0f , -6.0f , -7.0f},
            {1.0 , -3.0f , 7.0f , 4.0f}
        };
        */

        float arr2[4][4]= {
            {-4.0 , 2.0f , -2.0f , -3.0f},
            {9.0 , 6.0f , 2.0f , 6.0f},
            {0.0 , -5.0f , 1.0f , 5.0f},
            {0.0 , 0.0f , 0.0f , 0.0f}
        };

        TwoD::Matrix4x4 a2(arr2);
        CPPUNIT_ASSERT(a2.is_invertible() == false);

    }

}
