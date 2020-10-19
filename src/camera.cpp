#include "camera.h"
#include <math.h>

namespace Engine {

    Camera::Camera(int hsize, int vsize, float field_of_view):
    hsize(hsize),
    vsize(vsize),
    field_of_view(field_of_view),
    transform(TwoD::get_identity_matrix()){

        float half_view = tan(field_of_view / 2);
        float aspect = hsize / vsize;

        if(aspect >= 1) {
            half_width = half_view;
            half_view = half_width / aspect;
        } else {
            half_width = half_view * aspect;
            half_height = half_view;
        }

        pixel_size = (half_width * 2) / hsize;

    }


};
