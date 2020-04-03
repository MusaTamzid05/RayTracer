#ifndef TUPLE_H
#define TUPLE_H


namespace TwoD {

    struct Tuple {
        float x;
        float y;
        float z;
        float w;

        Tuple(float x , float y , float z , float w = 1);

        Tuple operator+=(const Tuple& tuple);
        Tuple operator-=(const Tuple& tuple);

        bool operator==(const Tuple& tuple);
        Tuple negate();
    };

    Tuple operator+(const Tuple& data1 , const Tuple& data2);
    Tuple operator-(const Tuple& data1 , const Tuple& data2);

};


#endif
