#include "tuple.h"
#include "equal.h"
#include <iostream>

namespace TwoD {
    Tuple::Tuple(float x , float y , float z , float w):
        x(x),
        y(y),
        z(z),
        w(w) {}
    
    Tuple Tuple::operator+=(const Tuple& tuple) {
        return Tuple(tuple.x + x , tuple.y + y , tuple.z + z , tuple.w + w );
    }


    Tuple Tuple::operator-=(const Tuple& tuple) {
        return Tuple(x - tuple.x , y - tuple.y , z - tuple.z , w - tuple.w );
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

}
