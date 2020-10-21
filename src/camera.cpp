#include "camera.h"
#include "canvas.h"
#include "world.h"
#include "ray.h"
#include "ray_world.h"
#include "point.h"
#include <math.h>

namespace Engine {

    Camera::Camera(float hsize, float vsize, float field_of_view):
    hsize(hsize),
    vsize(vsize),
    field_of_view(field_of_view),
    transform(TwoD::get_identity_matrix()){

        float half_view = tan(field_of_view / 2);
        float aspect = hsize / vsize;

        if(aspect >= 1) {
            half_width = half_view;
            half_height = half_width / aspect;
        } else {
            half_width = half_view * aspect;
            half_height = half_view;
        }

        pixel_size = (half_width * 2) / hsize;

    }

    Light::Ray* Camera::ray_for_pixel(float px, float py) {

        float xoffset = (px + 0.5f) * pixel_size;
        float yoffset = (py + 0.5f) * pixel_size;

        float world_x = half_width - xoffset;
        float world_y = half_height - yoffset;

        TwoD::Matrix inverse_transform;
        transform.inverse(inverse_transform);
        TwoD::Tuple pixel_tuple = inverse_transform * TwoD::Point(world_x, world_y, -1.0f);
        TwoD::Tuple origin = inverse_transform * TwoD::Point(0.0f, 0.0f, 0.0f);
        TwoD::Tuple dir_tuple = TwoD::Vector::convert_to_vector(pixel_tuple) - TwoD::Vector::convert_to_vector(origin);
        TwoD::Tuple dir_nor = TwoD::Vector::convert_to_vector(dir_tuple.normalize());

        return new Light::Ray(TwoD::Point::convert_to_point(origin), TwoD::Vector::convert_to_vector(dir_nor));

    }


    Canvas* Camera::render(RayWorld* world) {

        Canvas* image = new Canvas(hsize, vsize, nullptr);

        for(unsigned int y = 0; y < vsize - 1; y++) {
            for(unsigned int x = 0; x < hsize- 1; x++) {
                Light::Ray* ray = ray_for_pixel(x, y);
                Color color = world->color_at(ray);
                image->write_pixle(x, y, color);
            }
        }

        return image;
    }


};
