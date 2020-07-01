#include "sphere.h"
#include "ray.h"
#include <cmath>

namespace Light {


    Sphere::Sphere():
        center(TwoD::Point(0.0f, 0.0f, 0.0f)) {
            set_transform(TwoD::get_identity_matrix());
        }

    Sphere::Sphere(float x,  float y, float z):
        center(TwoD::Point(x, y, z))  {
            set_transform(TwoD::get_identity_matrix());
    }


    Sphere::Sphere(const TwoD::Point& center):
        center(center) {
            set_transform(TwoD::get_identity_matrix());

        }


    void Sphere::set_transform(const TwoD::Matrix4x4& matrix) {
        transform = matrix;
        transform.inverse(transform_inverse);

    }

    Light::IntersectionContainer  Sphere::intersect(const Light::Ray& ray) {


        Light::Ray new_ray =  ray.transform(transform_inverse);


        IntersectionContainer container;

        TwoD::Vector direction = new_ray.direction;
        TwoD::Tuple sphere_to_ray_tuple = new_ray.origin - TwoD::Point(0.0f, 0.0f, 0.0f);
        TwoD::Point sphere_to_ray = TwoD::Point::convert_to_point(sphere_to_ray_tuple);

        float a = direction.dot(direction);
        float b = sphere_to_ray.dot(direction) * 2;
        float c = sphere_to_ray.dot(sphere_to_ray) - 1;


        float discriminate = pow(b, 2) - 4 * a * c;

        if(discriminate < 0)
            return container;

        
        container.add(Intersection((-b - sqrt(discriminate)) / (2 * a), this));
        container.add(Intersection((-b + sqrt(discriminate)) / (2 * a), this));

        return container;


    }


    bool Sphere::operator==(const Light::Sphere& sphere) {
        return center == sphere.center;
    }


};
