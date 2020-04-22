#include "matrix.h"

namespace TwoD {

    Matrix::Matrix(int row , int col) {

        for(unsigned int i = 0 ; i < row; i++) {
            std::vector<int> current_data;
            for(unsigned int j = 0 ; j < col; j++) {
                current_data.push_back(0);
            }
            values.push_back(current_data);
        }
    }

};
