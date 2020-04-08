#include "canvas.h"
#include "operation.h"

namespace Engine {

    Canvas::Canvas(int width , int height):
        width(width),
        height(height) {
            init_pixles();
        }

    void Canvas::init_pixles() {

        for(unsigned int row = 0 ; row < height ; row++) {
            std::vector<Color> current_rows;
            for(unsigned int col = 0 ; col < width ; col++) {
                current_rows.push_back(Color(0.0f , 0.0f , 0.0f));
            }
            pixles.push_back(current_rows);
        }
    }

    void Canvas::show_pixles() {

        for(unsigned int row = 0 ; row < height ; row++)
            for(unsigned int col = 0 ; col < width ; col++) 
                std::cout << "(" << row << "," << col << ")" << " = " << pixles[row][col] << "\n";
    }


    
    void Canvas::save(const std::string& save_path) {

        std::string ppm_str = "";

        ppm_str += "p3\n";
        ppm_str += std::to_string(width) + " " + std::to_string(height) + "\n";
        ppm_str += "255\n";

        std::string red;
        std::string green;
        std::string blue;

        for(unsigned int row = 0 ; row < height ; row++) {
            for(unsigned int col = 0 ; col < width ; col++) {
                Color current_color = pixles[row][col];

                red =  std::to_string(Operation::scale_int(current_color.red() , 255.0f));
                green =  std::to_string(Operation::scale_int(current_color.green() , 255.0f));
                blue =  std::to_string(Operation::scale_int(current_color.blue() , 255.0f));

                std::string current_line = red + " " + green + " " + blue + " ";
                ppm_str += current_line;

            }

            ppm_str += "\n";

        }

        std::cout << ppm_str;
    }
};
