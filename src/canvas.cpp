#include "canvas.h"

namespace Engine {

    Canvas::Canvas(int width , int height):
        width(width),
        height(height) {
            init_pixles();
        }

    void Canvas::init_pixles() {

        for(unsigned int row = 0 ; row < width ; row++) {
            std::vector<Color> current_rows;
            for(unsigned int col = 0 ; col < height ; col++) {
                current_rows.push_back(Color(0.0f , 0.0f , 0.0f));
            }
            pixles.push_back(current_rows);
        }
    }

    void Canvas::show_pixles() {

        for(unsigned int row = 0 ; row < width ; row++)
            for(unsigned int col = 0 ; col < width ; col++) 
                std::cout << "(" << row << "," << col << ")" << " = " << pixles[row][col] << "\n";
    }


    
    void Canvas::save(const std::string& save_path) {

    }
};
