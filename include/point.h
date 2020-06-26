#ifndef POINT_H
#define POINT_H

#include "tuple.h"

namespace TwoD {

    struct Point : public Tuple {

        public:
            Point(float x , float y , float z):
                Tuple(x , y , z , 1.0){}

        static Point convert_to_point(const TwoD::Point& data);


        void operator+=(const Point& point);
        void operator-=(const Point& point);
        void operator*=(float value);
        void operator/=(float value);

        Point operator*(float value);
        Point operator/(float value);

        bool operator==(const Point& point);
        Point normalize();


    };

    Point operator+(const Point& data1 , const Point& data2);
    Point operator-(const Point& data1 , const Point& data2);
    Point operator*(const Point& data1 , const Point& data2);

};

#endif
