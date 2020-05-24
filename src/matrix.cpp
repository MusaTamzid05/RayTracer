#include "matrix.h"
#include <iostream>
#include "operation.h"
#include <math.h>

namespace TwoD {

    Matrix::Matrix(int row , int col):row(row),col(col) {

        for(unsigned int i = 0 ; i < row ; i++) {
            std::vector<float> current_data;
            for(unsigned int j = 0 ; j < col ; j++) {
                current_data.push_back(0);
            }
            values.push_back(current_data);
        }
    }

    Matrix4x4::Matrix4x4(float arr[4][4]):Matrix(4 , 4){

        for(unsigned int i = 0 ; i < row ; i++ ) 
            for(unsigned int j = 0 ; j < col ; j++)
                set(i , j , arr[i][j]);

    }


    Matrix3x3::Matrix3x3(float arr[3][3]):Matrix(3 , 3){

        for(unsigned int i = 0 ; i < row ; i++ ) 
            for(unsigned int j = 0 ; j < col ; j++)
                set(i , j , arr[i][j]);

    }


    Matrix2x2::Matrix2x2(float arr[2][2]):Matrix(2 , 2){

        for(unsigned int i = 0 ; i < row ; i++ ) 
            for(unsigned int j = 0 ; j < col ; j++)
                set(i , j , arr[i][j]);

    }

    std::ostream& operator<<(std::ostream& out , const Matrix& matrix) {
        out << "Matrix : (" << matrix.values.size() << "x" << matrix.values[0].size() << ")\n";


        for(unsigned int i = 0 ; i < matrix.values.size(); i++) {
            for(unsigned int j = 0 ; j < matrix.values[0].size(); j++) {
                std::cout << matrix.get(i , j) << " ";
            }
            std::cout << "\n";
        }
        return out;

    }

    bool Matrix::operator==(const Matrix& matrix) {


        if(row != matrix.row || col != matrix.col)
            return false;

        for(unsigned int i = 0 ; i < row ; i++)
            for(unsigned int j = 0 ; j < col; j++)
                if(!Operation::equal(values[i][j] , matrix.get(i , j))) 
                    return false;

        return true;
    }


    bool Matrix::operator!=(const Matrix& matrix) {
        return !(*this == matrix);
    }


    Matrix operator*(const Matrix& mat1 , const Matrix& mat2) {

        int row_size = mat1.row;
        int col_size = mat2.col;
        Matrix* result =  nullptr;

        if(row_size == 2 && col_size == 2)
            result = new Matrix2x2();
        else if(row_size == 3 && col_size == 3)
            result = new Matrix3x3();
        else if(row_size == 4 && col_size == 4)
            result = new Matrix4x4();
        


        for(unsigned int row = 0 ; row < row_size ; row++)
            for(unsigned int col = 0 ; col < col_size ; col++) {
                float value = mat1.get(row , 0) * mat2.get(0 , col) +
                    mat1.get(row , 1) * mat2.get(1 , col) +
                    mat1.get(row , 2) * mat2.get(2 , col) +
                    mat1.get(row , 3) * mat2.get(3 , col);

                result->set(row , col , value);
            }

        return *result;

    }
    
    Matrix Matrix::create_empty(int row , int col) {

        Matrix* matrix = nullptr;

        if(row == 2 && col == 2)
            matrix = new Matrix2x2();
        else if(row == 3 && col == 3)
            matrix = new Matrix3x3();
        else if(row == 4 && col == 4)
            matrix = new Matrix4x4();

        return *matrix;


    }
    
    Matrix Matrix::operator=(const Matrix& matrix) {
       
        Matrix result = Matrix::create_empty(row , col);

        for(unsigned int i = 0 ; i < row ; i++)
            for(unsigned int j = 0 ; j < col; j++) 
                result.values[i][j] = values[i][j];

        return result;

    }

    

    Matrix Matrix::transpose() {

        Matrix result = Matrix::create_empty(row , col);

        for(unsigned int i = 0 ; i < values.size() ; i++) {
            for(unsigned int j = 0 ; j < values[0].size(); j++) {
                result.values[j][i] = values[i][j];

            }
        }

        return result;
    }
    
    Tuple Matrix::operator*(const Tuple& tuple) {

        TwoD::Tuple result(0.0f , 0.0f , 0.0f , 0.0f);
        float sum;
        std::string tuple_attributes = "xyzw";

        for(unsigned int i = 0 ; i < row ; i++) {
            sum = 0.0f;
            for(unsigned int j = 0 ; j < col ; j++) {
                sum += values[i][j] * tuple.get_value(tuple_attributes[j]);
            }
            result.set_value(tuple_attributes[i] , sum);
        }
        return result;
    }


    Matrix Matrix::sub_matrix(int ignore_row , int ignore_col) {
    

        Matrix* result = nullptr;

        if(row == 4 && col == 4)
            result = new Matrix3x3();

        if(row == 3 && col == 3)
            result = new Matrix2x2();

        int current_row = 0;
        int current_col = 0;

        for(unsigned int i = 0 ; i < row ; i++) {
            if(i == ignore_row)
                continue;
            for(unsigned int j = 0 ; j < col ; j++) {
                if(j == ignore_col)
                    continue;

                result->values[current_row][current_col] = values[i][j];
                current_col += 1;
            }

            current_col = 0;
            current_row += 1;
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

        if(row == 2 && col == 2) 
            return (values[0][0] * values[1][1]) - (values[0][1] * values[1][0]);

        float result = 0.0f;
        for(unsigned i = 0 ; i < col ; i++)
            result = result + values[0][i] * cofactor(0 , i);

        return result;

    }

    

    float Matrix::minor_(int row , int col) {

        Matrix result = sub_matrix(row , col);
        return result.determinate();
    }


    
    float Matrix::cofactor(int row , int col) {
        
        float result = minor_(row , col);

        if((row + col) % 2 != 0)
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

        for(unsigned int i = 0 ; i < row ; i++)
            for(unsigned int j = 0 ; j < col ; j++) {
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

};
