#include "matrix.h"
#include <iostream>

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
                if(values[i][j] != matrix.get(i , j)) 
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

};
