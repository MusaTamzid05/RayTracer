#include "test_transformation.h"
#include "point.h"
#include "matrix.h"
#include "transformation.h"

namespace Testing {

    void TestTransformation::setUp() {

    }

    void TestTransformation::tearDown() {

    }

    void TestTransformation::testTransformationMatrixDefaultOrientation() {

        TwoD::Point from(0.0f, 0.0f, 0.0f);
        TwoD::Point to(0.0f, 0.0f, -1.0f);
        TwoD::Vector up(0.0f, 1.0f, 0.0f);

        TwoD::Matrix4x4 t = TwoD::Transformation::view_transform(from, to, up);
        CPPUNIT_ASSERT(t  == TwoD::get_identity_matrix());
    }


    void TestTransformation::testViewTransformationMovesTheWorld() {

        TwoD::Point from(0.0f, 0.0f, 8.0f);
        TwoD::Point to(0.0f, 0.0f, 0.0f);
        TwoD::Vector up(0.0f, 1.0f, 0.0f);

        TwoD::Matrix4x4 t = TwoD::Transformation::view_transform(from, to, up);
        CPPUNIT_ASSERT(t  == TwoD::Matrix4x4::translation(TwoD::Point(0.0f, 0.0f, -8.0f)));
    }


    void TestTransformation::testViewTransformationMatrixLookingInPosZDirection() {

        TwoD::Point from(0.0f, 0.0f, 0.0f);
        TwoD::Point to(0.0f, 0.0f, 1.0f);
        TwoD::Vector up(0.0f, 1.0f, 0.0f);

        TwoD::Matrix4x4 t = TwoD::Transformation::view_transform(from, to, up);
        CPPUNIT_ASSERT(t  == TwoD::Matrix4x4::scale(TwoD::Point(-1.0f, 1.0f, -1.0f)));
    }


    void TestTransformation::testAnArbitaryViewTransformation() {


        TwoD::Point from(1.0f, 3.0f, 2.0f);
        TwoD::Point to(4.0f, -2.0f, 8.0f);
        TwoD::Vector up(1.0f, 1.0f, 0.0f);

        TwoD::Matrix4x4 t = TwoD::Transformation::view_transform(from, to, up);

        TwoD::Matrix4x4 matrix;

        matrix.values[0][0] = -0.50709f;
        matrix.values[0][1] =  0.50709f;
        matrix.values[0][2] =  0.67612f;
        matrix.values[0][3] = -2.36643f;

        matrix.values[1][0] = 0.76772f;
        matrix.values[1][1] = 0.60609f;
        matrix.values[1][2] =  0.12122f;
        matrix.values[1][3] = -2.82843f;


        matrix.values[2][0] = -0.35857f;
        matrix.values[2][1] = 0.59761f;
        matrix.values[2][2] =  -0.71714f;
        matrix.values[2][3] = 0.0f;

        for(unsigned int i = 0; i < 3; i++)
            matrix.values[3][i] = -0.0f;

        matrix.values[3][3] = 1.0f;
        CPPUNIT_ASSERT(t  == matrix);

    }
};
