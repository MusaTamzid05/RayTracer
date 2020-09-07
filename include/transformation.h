#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include "matrix.h"
#include "vector.h"

namespace TwoD {
    namespace Transformation {

        TwoD::Matrix4x4 view_transform(
                const TwoD::Point& from,
                const TwoD::Point& to,
                const TwoD::Vector& up
                );
    };
};

#endif
