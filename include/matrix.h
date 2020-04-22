#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <sstream>

namespace TwoD {

    struct Matrix {

        Matrix(int row , int col);
        int get(int row , int col) const  { return values[row][col]; }


        std::vector<std::vector<int>> values;
        
    };

    std::ostream& operator<<(std::ostream& out , const Matrix& matrix);
}

#endif
