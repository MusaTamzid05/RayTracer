#ifndef CAMERA_H
#define CAMERA_H

#include "matrix.h"

namespace Engine {
    class Camera {
        public:
            Camera(float hsize, float vsize, float field_of_view);
            virtual ~Camera() {}

            float hsize;
            float vsize;
            float field_of_view;
            float half_width;
            float half_height;
            float pixel_size;
            TwoD::Matrix4x4 transform;
    };
};

#endif
