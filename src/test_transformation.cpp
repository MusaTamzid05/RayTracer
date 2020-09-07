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
};
