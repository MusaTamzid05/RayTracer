#include "camera.h"

namespace Engine {

    Camera::Camera(int hsize, int vsize, float field_of_view):
    hsize(hsize),
    vsize(vsize),
    field_of_view(field_of_view),
    transform(TwoD::get_identity_matrix()){

    }
};
