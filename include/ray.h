#ifndef RAY_H
#define RAY_H

#include "point.h"
#include "vector.h"
#include <iostream>
#include "matrix.h"

namespace Light {

    class Ray {

        public:

            Ray(const TwoD::Point& origin, const TwoD::Vector& direction);
            virtual ~Ray();

            TwoD::Point position(float distance); 

            TwoD::Point origin; 
            TwoD::Vector direction;

            Ray translation(const TwoD::Point& point);
            Ray scale(const TwoD::Point& point);


    };


    std::ostream& operator<<(std::ostream& out, const Ray& ray);
};

#endif
