#include "sphere.h"
#include "ray.h"
#include "intersection.h"
#include <cmath>

namespace Light {


    Sphere::Sphere():
        center(TwoD::Point(0.0f, 0.0f, 0.0f)),
        transform(TwoD::get_identity_matrix()) {

        }

    Sphere::Sphere(float x,  float y, float z):
        center(TwoD::Point(x, y, z)),
        transform(TwoD::get_identity_matrix()) {
    }


    Sphere::Sphere(const TwoD::Point& center):
        center(center),
        transform(TwoD::get_identity_matrix())  {
    }


    std::vector<Intersection> Sphere::intersect(const Light::Ray& ray) {


        TwoD::Matrix inverse_sphere_transformation = TwoD::Matrix4x4::create_empty(4, 4);

        transform.inverse(inverse_sphere_transformation);
        Light::Ray new_ray =  ray.transform(inverse_sphere_transformation);


        std::vector<Intersection> intersections;

        TwoD::Vector direction = new_ray.direction;
        TwoD::Tuple sphere_to_ray_tuple = new_ray.origin - TwoD::Point(0.0f, 0.0f, 0.0f);
        TwoD::Point sphere_to_ray = TwoD::Point::convert_to_point(sphere_to_ray_tuple);

        float a = direction.dot(direction);
        float b = sphere_to_ray.dot(direction) * 2;
        float c = sphere_to_ray.dot(sphere_to_ray) - 1;


        float discriminate = pow(b, 2) - 4 * a * c;

        if(discriminate < 0)
            return intersections;

        
        intersections.push_back(Intersection((-b - sqrt(discriminate)) / (2 * a), this));
        intersections.push_back(Intersection((-b + sqrt(discriminate)) / (2 * a), this));

        return intersections;


    }


    bool Sphere::operator==(const Light::Sphere& sphere) {
        return center == sphere.center;
    }


};
