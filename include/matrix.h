#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

namespace TwoD {

    struct Matrix {
        Matrix(int row , int col);


        std::vector<std::vector<int>> values;

    };
}

#endif
