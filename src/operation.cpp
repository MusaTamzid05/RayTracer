#include "operation.h"
#include <cmath>
#include <fstream>


namespace Operation {

    bool equal(float x , float y) {
        return std::fabs(x - y) < EPSILON;
    }

    Engine::Color tupleToColor(const TwoD::Tuple& data) {
        return Engine::Color(data.x , data.y , data.z);
    }

    
    int scale_int(float value , float max_value) {

        int result = value *  max_value;

        if (result < 0)
            result = 0;
        else if(result > (int)max_value)
            result = (int)max_value;

        return result;
    }

    void write_file(const std::string& filename , const std::string& text , bool append) {
        
        std::ofstream output_file;

        if(append)
            output_file.open(filename , std::ios::out | std::ios::app);
        else
            output_file.open(filename);

        output_file << text;
        output_file.close();
    }
};
