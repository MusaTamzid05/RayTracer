#include "transformation.h"

namespace TwoD {
    namespace Transformation {

        TwoD::Matrix4x4 view_transform(
                const TwoD::Point& from,
                const TwoD::Point& to,
                const TwoD::Vector& up
                ) {

            TwoD::Tuple forward_ = to - from;
            TwoD::Vector forward_vector = TwoD::Vector::convert_to_vector(forward_.normalize());


            TwoD::Vector up_normalize = TwoD::Vector::convert_to_vector(up.normalize());
            TwoD::Vector left = forward_vector.cross(up_normalize);
            TwoD::Tuple true_up = left.cross(forward_vector);

            TwoD::Matrix4x4 orientation;

            orientation.values[0][0] = left.x;
            orientation.values[0][1] = left.y;
            orientation.values[0][2] = left.z;
            orientation.values[0][3] = 0.0f;

            orientation.values[1][0] = true_up.x;
            orientation.values[1][1] = true_up.y;
            orientation.values[1][2] = true_up.z;
            orientation.values[1][3] = 0.0f;


            orientation.values[2][0] = - forward_vector.x;
            orientation.values[2][1] = - forward_vector.y;
            orientation.values[2][2] = - forward_vector.z;
            orientation.values[2][3] = 0.0f;

            for(unsigned int i = 0 ; i < 3; i++)
                orientation.values[3][i] = 0.0f;

            orientation.values[3][3] = 1.0f;

            TwoD::Matrix result = orientation * TwoD::Matrix4x4::translation(TwoD::Point(-from.x, -from.y, -from.z));

            return  TwoD::Matrix4x4::convert_matrix4x4(result);

        }
    };
};
