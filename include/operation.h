#ifndef OPERATION_H
#define OPERATION_H

#include "tuple.h"
#include "color.h"

namespace Operation {
    const float EPSILON = 0.0001f;
    Engine::Color tupleToColor(const TwoD::Tuple& data);
    bool equal(float value1 , float value2);
    Engine::Color tupleToColor(const TwoD::Tuple& data);
};

#endif
