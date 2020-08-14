#include "tuple.h"
#include "operation.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

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

    
    bool Tuple::operator==(const Tuple& tuple) const {

        return Operation::equal(x , tuple.x) &&
            Operation::equal(y , tuple.y) && 
            Operation::equal(z , tuple.z) &&
            Operation::equal(w , tuple.w);
    }

    Tuple Tuple::operator*(float value) {

        x *= value;
        y *= value;
        z *= value;
        w *= value;

        return *this;
    }

    Tuple Tuple::operator/(float value) {

        x /= value;
        y /= value;
        z /= value;
        w /= value;

        return *this;
    }


    Tuple operator+(const Tuple& data1 , const Tuple& data2) {
        return Tuple(data1.x + data2.x , data1.y + data2.y , data1.z + data2.z , data1.w + data2.w);
    }

    Tuple operator-(const Tuple& data1 , const Tuple& data2) {
        return Tuple(data1.x - data2.x , data1.y - data2.y , data1.z - data2.z , data1.w - data2.w);
    }

    Tuple operator*(const Tuple& data1 , const Tuple& data2) {
        return Tuple(data1.x * data2.x , data1.y * data2.y , data1.z * data2.z , data1.w * data2.w);
    }

    Tuple Tuple::negate() const {

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

    
    float Tuple::get_value(const char name) const  {

        if(name == 'x')
            return x;
        else if(name == 'y')
            return y;
        else if(name == 'z')
            return z;
        else if(name == 'w')
            return w;

        throw std::runtime_error("Invalid attribe asked in tuple");

    }

    void Tuple::set_value(const char name , float value) {

        if(name == 'x') {
            x = value;
            return;
        }
        else if(name == 'y') {
            y = value;
            return;
        }
        else if(name == 'z') {
            z = value;
            return;
        }
        else if(name == 'w') {
            w = value;
            return;
        }

        throw std::runtime_error("Invalid attribe set in tuple");
    }

    Tuple Tuple::mul(float value) {
        Tuple data = *this;
        return data * value;
    }


    Tuple Tuple::div(float value) {
        Tuple data = *this;
        return data / value;
    }

    Tuple Tuple::negative() const {
        Tuple data = *this;
        return Tuple(-data.x, -data.y, -data.z, -data.w);
    }
}
