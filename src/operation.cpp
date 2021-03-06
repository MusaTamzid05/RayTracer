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


    std::string limit_line(const std::string& str , int character_limit) {

        if(str.size() <= character_limit)
            return str;

        std::string result = str;
        int index = character_limit;
        int increment = character_limit;
    

        while(index < str.size()) {

            if(result[index] == ' ')  {
                result[index] = '\n';
                index += increment;
                continue;

            } 

            int temp_index = index + 1;
            while(result[temp_index] != ' ')
                temp_index += 1;
            result[temp_index] = '\n';

            index =  temp_index + 1 + increment;

        }

        return result;
    }


    std::vector<std::string> read_lines_from(const std::string& path) {

        std::vector<std::string> lines;

        std::fstream input_file;
        input_file.open(path);

        if(!input_file.is_open()) {
            std::cerr << "Could not open " << path << "\n";
            return lines;
        }

        std::string line;

        while(std::getline(input_file ,line))
            lines.push_back(line);

        input_file.close();

        return lines;
    }


    std::string trim(const std::string& str) {

        std::string result = str;
        result.erase(str.find_last_not_of(" \n\r\t") + 1);
        return result;
    }
};
