#include "sphere.h"
#include "ray.h"
#include <cmath>
#include "material.h"

namespace Light {


    Sphere::Sphere():
        center(TwoD::Point(0.0f, 0.0f, 0.0f)),
        material(new Light::Material()) {
            set_transform(TwoD::get_identity_matrix());
        }

    Sphere::Sphere(float x,  float y, float z):
        center(TwoD::Point(x, y, z)),
        material(new Light::Material()) {
            set_transform(TwoD::get_identity_matrix());
    }


    Sphere::Sphere(const TwoD::Point& center):
        center(center),
        material(new Light::Material()){
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


    TwoD::Vector Sphere::normal_at(const TwoD::Point& world_point) {

        TwoD::Tuple object_point_tuple = transform_inverse * world_point;
        TwoD::Tuple object_normal = object_point_tuple - TwoD::Point(0.0f, 0.0f, 0.0f);
        TwoD::Tuple world_normal_tuple  = transform_inverse.transpose() * object_normal;
        world_normal_tuple.w = 0.0f;
        TwoD::Tuple nor = world_normal_tuple.normalize();

        return TwoD::Vector::convert_to_vector(nor);

    }

};
