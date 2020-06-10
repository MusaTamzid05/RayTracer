#ifndef RAY_H
#define RAY_H

#include "point.h"
#include "vector.h"

namespace Light {

    class Ray {

        public:

            Ray(const TwoD::Point& origin, const TwoD::Vector& direction);
            virtual ~Ray();


            TwoD::Point origin; 
            TwoD::Vector direction;


    };
};

#endif
