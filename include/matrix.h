#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <sstream>
#include "tuple.h"
#include "point.h"

namespace TwoD {

    struct Matrix {

        Matrix(int rows , int cols);
        Matrix();
        Matrix(const Matrix& matrix);

        virtual ~Matrix();

        float get(int row , int col) const  { return values[row][col]; }
        void set(int row , int col , float value) { values[row][col] = value; }

        int rows;
        Matrix transpose();
        int cols;

        float** values;

        bool operator==(const Matrix& matrix);
        bool operator!=(const Matrix& matrix);
        void operator=(const Matrix& matrix);
        Tuple operator*(const Tuple& tuple);

        Matrix sub_matrix(int ignore_row , int ignore_col);
        
        static Matrix create_empty(int row , int col);
        float determinate();
        float minor_(int row , int col);
        float cofactor(int row , int col);

        bool is_invertible();

        void inverse(Matrix& result);


        
    };

    Matrix operator*(const Matrix& mat1 , const Matrix& mat2);

    struct Matrix4x4 : public Matrix {
        Matrix4x4(float arr[4][4]);
        Matrix4x4():Matrix(4,4){}

        static Matrix4x4 translation(const TwoD::Point& point);
        static Matrix4x4 scale(const TwoD::Point& point);

        // returns a matrix that will roate a point
        // when multiply

        static Matrix4x4 rotate_x(float radian);
        static Matrix4x4 rotate_y(float radian);
        static Matrix4x4 rotate_z(float radian);
        static Matrix4x4 shearing(float xy , float  xz , float yx, float yz, float zx, float zy);

        static Matrix4x4 convert(const Matrix& matrix);
        static Matrix4x4 convert_matrix4x4(const Matrix& matrix);
    };


    struct Matrix3x3 : public Matrix {
        Matrix3x3(float arr[3][3]);
        Matrix3x3():Matrix(3,3){}
    };


    struct Matrix2x2 : public Matrix {
        Matrix2x2(float arr[2][2]);
        Matrix2x2():Matrix(2,2){}
    };

    Matrix4x4 get_identity_matrix();

    std::ostream& operator<<(std::ostream& out , const Matrix& matrix);
}

#endif
