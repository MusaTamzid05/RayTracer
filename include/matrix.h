#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <sstream>

namespace TwoD {

    struct Matrix {

        Matrix(int row , int col);
        float get(int row , int col) const  { return values[row][col]; }
        void set(int row , int col , float value) { values[row][col] = value; }


        int row;
        int col;

        std::vector<std::vector<float>> values;
        
    };

    struct Matrix4x4 : public Matrix {
        Matrix4x4(float arr[4][4]);

    };

    std::ostream& operator<<(std::ostream& out , const Matrix& matrix);
}

#endif
