#include "matrix.h"
#include <iostream>

namespace TwoD {

    Matrix::Matrix(int row , int col) {

        for(unsigned int i = 0 ; i < row ; i++) {
            std::vector<int> current_data;
            for(unsigned int j = 0 ; j < col ; j++) {
                current_data.push_back(0);
            }
            values.push_back(current_data);
        }
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
