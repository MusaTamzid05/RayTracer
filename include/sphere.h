#ifndef SPHERE_H
#define SPHERE_H

#include "point.h"
#include "vector.h"
#include "matrix.h"
#include "intersection.h"
#include <vector>

namespace Light {

    class Ray;


    class Sphere {

        public:
            Sphere();
            Sphere(float x, float y, float z);
            Sphere(const TwoD::Point& center);

            virtual ~Sphere() {}


            TwoD::Point center;

            Light::IntersectionContainer  intersect(const Light::Ray& ray);

            bool operator==(const Light::Sphere& sphere);

            void set_transform(const TwoD::Matrix4x4& matrix);
            TwoD::Matrix get_transform() { return transform; } 

            TwoD::Vector normal_at(const TwoD::Point& point);

        private:

            TwoD::Matrix4x4 transform;
            TwoD::Matrix transform_inverse;


    };

};

#endif
