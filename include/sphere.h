#ifndef SPHERE_H
#define SPHERE_H

#include "point.h"
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

            std::vector<float> intersect(const Light::Ray& ray);


    };

};

#endif
