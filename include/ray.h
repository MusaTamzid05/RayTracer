#ifndef RAY_H
#define RAY_H

#include "point.h"
#include "vector.h"
#include <iostream>

namespace Light {

    class Ray {

        public:

            Ray(const TwoD::Point& origin, const TwoD::Vector& direction);
            virtual ~Ray();

            TwoD::Point position(float distance); 

            TwoD::Point origin; 
            TwoD::Vector direction;


    };


    std::ostream& operator<<(std::ostream& out , const Ray& ray);
};

#endif
