#include "sphere.h"
#include "ray.h"
#include "intersection.h"
#include <cmath>

namespace Light {


    Sphere::Sphere():
        center(TwoD::Point(0.0f, 0.0f, 0.0f)){

        }

    Sphere::Sphere(float x,  float y, float z):
        center(TwoD::Point(x, y, z)){
    }


    Sphere::Sphere(const TwoD::Point& center):
        center(center){
    }


    std::vector<Intersection> Sphere::intersect(const Light::Ray& ray) {

        std::vector<Intersection> intersections;

        TwoD::Vector direction = ray.direction;
        TwoD::Tuple sphere_to_ray_tuple = ray.origin - TwoD::Point(0.0f, 0.0f, 0.0f);
        TwoD::Point sphere_to_ray = TwoD::Point::convert_to_point(sphere_to_ray_tuple);

        float a = direction.dot(direction);
        float b = sphere_to_ray.dot(ray.direction) * 2;
        float c = sphere_to_ray.dot(sphere_to_ray) - 1;


        float discriminate = pow(b, 2) - 4 * a * c;

        if(discriminate < 0)
            return intersections;

        
        intersections.push_back(Intersection((-b - sqrt(discriminate)) / (2 * a), this));
        intersections.push_back(Intersection((-b + sqrt(discriminate)) / (2 * a), this));

        return intersections;


    }

};
