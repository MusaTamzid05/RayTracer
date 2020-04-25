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

        bool operator==(const Matrix& matrix);
        bool operator!=(const Matrix& matrix);
        
    };

    struct Matrix4x4 : public Matrix {
        Matrix4x4(float arr[4][4]);
    };


    struct Matrix3x3 : public Matrix {
        Matrix3x3(float arr[3][3]);
    };


    struct Matrix2x2 : public Matrix {
        Matrix2x2(float arr[2][2]);
    };

    std::ostream& operator<<(std::ostream& out , const Matrix& matrix);
}

#endif
