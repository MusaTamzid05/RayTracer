#include "canvas.h"
#include "operation.h"
#include <SFML/Graphics.hpp>

namespace Engine {

    Canvas::Canvas(int width , int height):
        width(width),
        height(height) {
            init_pixles();
        }

    Canvas::~Canvas() {
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


    void Canvas::write_pixle(int row , int col , const Color& color) {
        pixles[row][col] = color;
    }
    
    void Canvas::save(const std::string& save_path) {

        std::string ppm_str = "";

        ppm_str += "P3\n";
        ppm_str += std::to_string(width) + " " + std::to_string(height) + "\n";
        ppm_str += "255\n";

        std::string red;
        std::string green;
        std::string blue;

        std::string current_line;

        for(unsigned int row = 0 ; row < height ; row++) {
            current_line = "";
            for(unsigned int col = 0 ; col < width ; col++) {
                Color current_color = pixles[row][col];

                red =  std::to_string(Operation::scale_int(current_color.red() , 255.0f));
                green =  std::to_string(Operation::scale_int(current_color.green() , 255.0f));
                blue =  std::to_string(Operation::scale_int(current_color.blue() , 255.0f));

                current_line += red + " " + green + " " + blue + " ";
            }

            current_line = Operation::limit_line(current_line , 70);

            ppm_str += current_line + "\n";
        }

        Operation::write_file(save_path , ppm_str);
        std::cout << "Sucessfully written data to " << save_path << "\n";
    }

    void Canvas::draw(sf::RenderWindow* window) {

        std::vector<sf::CircleShape> shapes;

        for(unsigned int row = 0 ; row < height ; row++) {
            for(unsigned int col = 0 ; col < width ; col++) {
                Engine::Color color = get_pixle(row , col);
                sf::CircleShape shape(1.0f);
                shape.setPosition(col , row);
                shape.setFillColor(sf::Color(color.red() , color.green() , color.blue()));
                shapes.push_back(shape);

            }
        }

        for(sf::CircleShape& shape : shapes)
            window->draw(shape);

        std::cout << "Canvas drawn\n";
    }
};
