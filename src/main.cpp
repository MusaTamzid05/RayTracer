#include "unit_test.h"
#include "app.h"
#include "color.h"
#include <iostream>
#include "world.h"
#include "matrix.h"

std::vector<TwoD::Point> get_clock_points(float radius, const TwoD::Point& center = TwoD::Point(0.0f, .0f, 0.0f)) {

    std::vector<TwoD::Point> points;
    TwoD::Matrix4x4 rotation_mat;
    TwoD::Tuple result(0.0f, 0.0f, 1.0f);;
    TwoD::Point twelve(0.0f, 0.0f, 1.0f);

    for(unsigned int i = 1 ; i <= 12 ; i++) {

        if (i != 1) {
            TwoD::Matrix4x4 rotation_mat = TwoD::Matrix4x4::rotate_y(i * M_PI / 6);
            result =  rotation_mat * twelve;
        } else 
            result =  twelve;


        TwoD::Point temp_point = TwoD::Point(result.x * radius, result.z * radius, 0.0f);
        TwoD::Tuple center_tuple = temp_point + center;
        points.push_back(TwoD::Point(center_tuple.x, center_tuple.y, 0.0f));
    }


    for(TwoD::Point point : points)
        std::cout << point << "\n";

    return points;

}


int main_app()  {

    Engine::App app;
    app.run();
    


    return 0;
}

int run_test() {
    return Testing::run_test();
}

int main(int argc , char** argv) {
    return main_app();
}
