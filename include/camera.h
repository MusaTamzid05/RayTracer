#ifndef CAMERA_H
#define CAMERA_H

#include "matrix.h"

namespace Engine {
    class Camera {
        public:
            Camera(int hsize, int vsize, float field_of_view);
            virtual ~Camera() {}

            int hsize;
            int vsize;
            float field_of_view;
            TwoD::Matrix4x4 transform;
    };
};

#endif
