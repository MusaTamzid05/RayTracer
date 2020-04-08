#ifndef TUPLE_H
#define TUPLE_H

#include <iostream>

namespace TwoD {

    struct Tuple {
        float x;
        float y;
        float z;
        float w;

        Tuple(float x , float y , float z , float w = 1);

        void operator+=(const Tuple& tuple);
        void operator-=(const Tuple& tuple);
        void operator*=(float value);
        void operator/=(float value);

        Tuple operator*(float value);
        Tuple operator/(float value);

        bool operator==(const Tuple& tuple);
        Tuple negate();

        float magnitude();
        Tuple normalize();
        float dot(const Tuple& data);
        
    };

    Tuple operator+(const Tuple& data1 , const Tuple& data2);
    Tuple operator-(const Tuple& data1 , const Tuple& data2);
    Tuple operator*(const Tuple& data1 , const Tuple& data2);

    std::ostream& operator<<(std::ostream& out , const Tuple& obj);

};


#endif
