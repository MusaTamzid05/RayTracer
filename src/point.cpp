#include "point.h"
#include "operation.h"

namespace TwoD {

    Point Point::convert_to_point(const TwoD::Tuple& data) {
        TwoD::Point point(data.x, data.y, data.z);
        point.w = data.w;
        return point;
    }


    void Point::operator+=(const Point& point) {

        x += point.x;
        y += point.y;
        z += point.z;
    }


    void Point::operator-=(const Point& point) {

        x -= point.x;
        y -= point.y;
        z -= point.z;
    }

    void Point::operator*=(float value) {

        x *= value;
        y *= value;
        z *= value;
    }

    
    void Point::operator/=(float value) {

        x /= value;
        y /= value;
        z /= value;
    }

    
    bool Point::operator==(const Point& point) {

        return Operation::equal(x , point.x) &&
            Operation::equal(y , point.y) && 
            Operation::equal(z , point.z);
    }

    Point Point::operator*(float value) {

        x *= value;
        y *= value;
        z *= value;

        return *this;
    }

    Point Point::operator/(float value) {

        x /= value;
        y /= value;
        z /= value;

        return *this;
    }


    Point operator+(const Point& data1 , const Point& data2) {
        return Point(data1.x + data2.x , data1.y + data2.y , data1.z + data2.z);
    }

    Point operator-(const Point& data1 , const Point& data2) {
        return Point(data1.x - data2.x , data1.y - data2.y , data1.z - data2.z);
    }

    Point operator*(const Point& data1 , const Point& data2) {
        return Point(data1.x * data2.x , data1.y * data2.y , data1.z * data2.z);
    }


    Point Point::normalize() {

        float mag = magnitude();
        return Point(x / mag , y / mag , z / mag);

    }

};
