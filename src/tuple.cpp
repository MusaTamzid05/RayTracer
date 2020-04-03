#include "tuple.h"
#include "equal.h"
#include <iostream>
#include <cmath>

namespace TwoD {
    Tuple::Tuple(float x , float y , float z , float w):
        x(x),
        y(y),
        z(z),
        w(w) {}
    
    void Tuple::operator+=(const Tuple& tuple) {

        x += tuple.x;
        y += tuple.y;
        z += tuple.z;
        w += tuple.w;
    }


    void Tuple::operator-=(const Tuple& tuple) {

        x -= tuple.x;
        y -= tuple.y;
        z -= tuple.z;
        w -= tuple.w;
    }

    void Tuple::operator*=(float value) {

        x *= value;
        y *= value;
        z *= value;
        w *= value;
    }

    
    void Tuple::operator/=(float value) {

        x /= value;
        y /= value;
        z /= value;
        w /= value;
    }

    
    bool Tuple::operator==(const Tuple& tuple) {

        return Operation::equal(x , tuple.x) &&
            Operation::equal(y , tuple.y) && 
            Operation::equal(z , tuple.z) &&
            Operation::equal(w , tuple.w);
    }


    Tuple operator+(const Tuple& data1 , const Tuple& data2) {
        return Tuple(data1.x + data2.x , data1.y + data2.y , data1.z + data2.z , data1.w + data2.w);
    }

    Tuple operator-(const Tuple& data1 , const Tuple& data2) {
        return Tuple(data1.x - data2.x , data1.y - data2.y , data1.z - data2.z , data1.w - data2.w);
    }


    Tuple Tuple::negate() {

        Tuple zero = Tuple(0.0f , 0.0f , 0.0f , 0.0f);
        return zero - *this;
    }


    std::ostream& operator<<(std::ostream& out , const Tuple& obj) {
        out << obj.x << " , " << obj.y << " , " << obj.z  << " , " << obj.w;
        return out;
    }

    float Tuple::magnitude() {
        return sqrt(pow(x , 2) + pow(y , 2) + pow(z , 2) + pow(w , 2));
    }

    Tuple Tuple::normalize() {

        float mag = magnitude();
        return Tuple(x / mag , y / mag , z / mag , w /mag);

    }

    float Tuple::dot(const Tuple& data) {
        return x * data.x + y * data.y + z * data.z + w * data.w;
    }

}
