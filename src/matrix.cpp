#include "matrix.h"
#include <iostream>
#include "operation.h"
#include <math.h>

namespace TwoD {

    Matrix::Matrix(int rows , int cols):rows(rows),cols(cols) {

        values = new float*[rows];

        for(unsigned int i = 0 ; i < cols ; i++)
            values[i] = new float[cols];

        for (unsigned r = 0 ; r < rows; r++)
            for (unsigned c = 0 ; c < cols; c++)
                values[r][c] = 0;

    }

    Matrix::Matrix():rows(4),cols(4) {

        values = new float*[rows];

        for(unsigned int i = 0 ; i < cols ; i++)
            values[i] = new float[cols];

        for (unsigned r = 0 ; r < rows; r++)
            for (unsigned c = 0 ; c < cols; c++)
                values[r][c] = 0;

    }

    Matrix::~Matrix() {

    }

     Matrix::Matrix(const Matrix& matrix) {

         rows = matrix.rows;
         cols = matrix.cols;
         values = matrix.values;

        }


    Matrix4x4::Matrix4x4(float arr[4][4]):Matrix(4 , 4){

        for(unsigned int i = 0 ; i < rows ; i++ ) 
            for(unsigned int j = 0 ; j < cols ; j++)
                set(i , j , arr[i][j]);


    }


    Matrix3x3::Matrix3x3(float arr[3][3]):Matrix(3 , 3){


        for(unsigned int i = 0 ; i < rows ; i++ ) 
            for(unsigned int j = 0 ; j < cols ; j++)
                set(i , j , arr[i][j]);

    }


    Matrix2x2::Matrix2x2(float arr[2][2]):Matrix(2 , 2){

        for(unsigned int i = 0 ; i < rows ; i++ ) 
            for(unsigned int j = 0 ; j < cols ; j++)
                set(i , j , arr[i][j]);

    }

    std::ostream& operator<<(std::ostream& out , const Matrix& matrix) {

        for(unsigned int r = 0; r < matrix.rows ; r++) {
            for(unsigned int c = 0; c < matrix.cols; c++)
                out << matrix.values[r][c] << " ";
            out << "\n";
        }
        return out;

    }

    bool Matrix::operator==(const Matrix& matrix) {


        if(rows != matrix.rows || cols != matrix.cols)
            return false;

        for(unsigned int i = 0 ; i < rows ; i++)
            for(unsigned int j = 0 ; j < cols; j++)
                if(!Operation::equal(values[i][j] , matrix.get(i , j))) 
                    return false;

        return true;
    }


    bool Matrix::operator!=(const Matrix& matrix) {
        return !(*this == matrix);
    }


    Matrix operator*(const Matrix& mat1 , const Matrix& mat2) {

        int rows_size = mat1.rows;
        int cols_size = mat2.cols;
        Matrix* result =  nullptr;

        if(rows_size == 2 && cols_size == 2)
            result = new Matrix2x2();
        else if(rows_size == 3 && cols_size == 3)
            result = new Matrix3x3();
        else if(rows_size == 4 && cols_size == 4)
            result = new Matrix4x4();
        


        for(unsigned int rows = 0 ; rows < rows_size ; rows++)
            for(unsigned int cols = 0 ; cols < cols_size ; cols++) {
                float value = mat1.get(rows , 0) * mat2.get(0 , cols) +
                    mat1.get(rows , 1) * mat2.get(1 , cols) +
                    mat1.get(rows , 2) * mat2.get(2 , cols) +
                    mat1.get(rows , 3) * mat2.get(3 , cols);

                result->set(rows , cols , value);
            }

        return *result;

    }
    
    Matrix Matrix::create_empty(int rows , int cols) {

        Matrix* matrix = nullptr;

        if(rows == 2 && cols == 2)
            matrix = new Matrix2x2();
        else if(rows == 3 && cols == 3)
            matrix = new Matrix3x3();
        else if(rows == 4 && cols == 4)
            matrix = new Matrix4x4();

        return *matrix;


    }
    
    void Matrix::operator=(const Matrix& matrix) {

        for(unsigned int i = 0 ; i < rows ; i++)
            for(unsigned int j = 0 ; j < cols; j++) 
                values[i][j] = matrix.values[i][j];


    }

    

    Matrix Matrix::transpose() {

        Matrix result = Matrix::create_empty(rows , cols);

        for(unsigned int r = 0 ; r < rows; r++) {
            for(unsigned int c = 0 ; c < cols; c++) {
                result.values[r][c] = values[c][r];

            }
        }

        return result;
    }
    
    Tuple Matrix::operator*(const Tuple& tuple) {

        TwoD::Tuple result(0.0f , 0.0f , 0.0f , 0.0f);
        float sum;
        std::string tuple_attributes = "xyzw";

        for(unsigned int i = 0 ; i < rows ; i++) {
            sum = 0.0f;
            for(unsigned int j = 0 ; j < cols ; j++) {
                sum += values[i][j] * tuple.get_value(tuple_attributes[j]);
            }
            result.set_value(tuple_attributes[i] , sum);
        }
        return result;
    }


    Matrix Matrix::sub_matrix(int ignore_rows , int ignore_cols) {
    

        Matrix* result = nullptr;

        if(rows == 4 && cols == 4)
            result = new Matrix3x3();

        if(rows == 3 && cols == 3)
            result = new Matrix2x2();

        int current_rows = 0;
        int current_cols = 0;

        for(unsigned int i = 0 ; i < rows ; i++) {
            if(i == ignore_rows)
                continue;
            for(unsigned int j = 0 ; j < cols ; j++) {
                if(j == ignore_cols)
                    continue;

                result->values[current_rows][current_cols] = values[i][j];
                current_cols += 1;
            }

            current_cols = 0;
            current_rows += 1;
        }

        return *result;
    }

    Matrix4x4 get_identity_matrix() {
        
        float arr[4][4] = {
            {1.0f , 0.0f , 0.0f , 0.0f},
            {0.0f , 1.0f , 0.0f , 0.0f},
            {0.0f , 0.0f , 1.0f , 0.0f},
            {0.0f , 0.0f , 0.0f , 1.0f}
        };

        Matrix4x4 identity_matrix(arr);

        return identity_matrix;

    }


    float Matrix::determinate() {

        if(rows == 2 && cols == 2) 
            return (values[0][0] * values[1][1]) - (values[0][1] * values[1][0]);

        float result = 0.0f;
        for(unsigned i = 0 ; i < cols ; i++)
            result = result + values[0][i] * cofactor(0 , i);

        return result;

    }

    

    float Matrix::minor_(int rows , int cols) {

        Matrix result = sub_matrix(rows , cols);
        return result.determinate();
    }


    
    float Matrix::cofactor(int rows , int cols) {
        
        float result = minor_(rows , cols);

        if((rows + cols) % 2 != 0)
            return -result;

        return result;
    }


    bool Matrix::is_invertible() {
        return determinate() == 0 ? false : true;
    }


    
    void Matrix::inverse(Matrix& result) {

        if(!is_invertible()) {
            std::cerr << "matrix is not ivertiable.\n";
            return;
        }

        float cofactor_value;
        float current_value;

        for(unsigned int i = 0 ; i < rows ; i++)
            for(unsigned int j = 0 ; j < cols ; j++) {
                cofactor_value = cofactor(i , j);
                current_value  = cofactor_value / determinate();
                result.set(j , i , current_value);
            }

    }
    
    Matrix4x4 Matrix4x4::translation(const TwoD::Point& point) {

        Matrix4x4 identity_matrix = get_identity_matrix();

        identity_matrix.values[0][3] = point.x;
        identity_matrix.values[1][3] = point.y;
        identity_matrix.values[2][3] = point.z;
        identity_matrix.values[3][3] = 1.0f;

        return identity_matrix;
    }

    Matrix4x4 Matrix4x4::scale(const TwoD::Point& point) {

        Matrix4x4 identity_matrix = get_identity_matrix();

        identity_matrix.values[0][0] = point.x;
        identity_matrix.values[1][1] = point.y;
        identity_matrix.values[2][2] = point.z;
        identity_matrix.values[3][3] = 1.0f;

        return identity_matrix;
    }

    Matrix4x4 Matrix4x4::rotate_x(float radian) {

        Matrix4x4 mat = get_identity_matrix();

        mat.values[1][1] = cos(radian);
        mat.values[1][2] = -sin(radian);
        mat.values[2][1] = sin(radian);
        mat.values[2][2] = cos(radian);

        return mat;
    }


    Matrix4x4 Matrix4x4::rotate_y(float radian) {

        Matrix4x4 mat = get_identity_matrix();

        mat.values[0][0] = cos(radian);
        mat.values[0][2] = sin(radian);
        mat.values[2][0] = -sin(radian);
        mat.values[2][2] = cos(radian);

        return mat;
    }

    
    Matrix4x4 Matrix4x4::rotate_z(float radian) {

        Matrix4x4 mat = get_identity_matrix();

        mat.values[0][0] = cos(radian);
        mat.values[0][1] = -sin(radian);
        mat.values[1][0] = sin(radian);
        mat.values[1][1] = cos(radian);

        return mat;
    }

    
    Matrix4x4 Matrix4x4::shearing(float xy , float  xz , float yx, float yz, float zx, float zy) {

        Matrix4x4 mat = get_identity_matrix();

        mat.values[0][1] = xy;
        mat.values[0][2] = xz;
        mat.values[1][0] = yx;
        mat.values[1][2] = yz;
        mat.values[2][0] = zx;
        mat.values[2][1] = zy;

        return mat;
    }


    Matrix4x4 Matrix4x4::convert(const Matrix& matrix) {

        Matrix4x4 new_matrix;

        for(unsigned int i = 0 ; i < 4 ; i++)
            for(unsigned int j = 0 ; j < 4 ; j++)
                new_matrix.values[i][j] = matrix.values[i][j];

        return new_matrix;
    }



    Matrix4x4 Matrix4x4::convert_matrix4x4(const Matrix& matrix) {

        TwoD::Matrix4x4 new_matrix;

        for(unsigned int i = 0; i < 4; i++)
            for(unsigned int j = 0; j < 4; j++)
                new_matrix.values[i][j] = matrix.values[i][j];

        return new_matrix;
    }

};
