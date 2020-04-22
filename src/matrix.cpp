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

};
