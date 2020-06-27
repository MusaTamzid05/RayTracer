#ifndef POINT_H
#define POINT_H

#include "tuple.h"

namespace TwoD {

    struct Point : public Tuple {

        public:
            Point(float x , float y , float z):
                Tuple(x , y , z , 1.0){}

        static Point convert_to_point(const TwoD::Tuple& data);



    };


};

#endif
