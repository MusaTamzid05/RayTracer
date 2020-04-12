#ifndef OPERATION_H
#define OPERATION_H

#include "tuple.h"
#include "color.h"
#include <vector>

namespace Operation {
    const float EPSILON = 0.0001f;
    Engine::Color tupleToColor(const TwoD::Tuple& data);
    bool equal(float value1 , float value2);
    Engine::Color tupleToColor(const TwoD::Tuple& data);

    int scale_int(float value , float max_value);

    void write_file(const std::string& filename , const std::string& text , bool append = false);

    std::string limit_line(const std::string& str , int character_limit);

    std::vector<std::string> read_lines_from(const std::string& path);
};

#endif
