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
};
