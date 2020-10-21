#include "canvas.h"
#include <iostream>
#include "operation.h"
#include "world.h"
#include "pixle_data.h"

namespace Engine {

    Canvas::Canvas(int width , int height , SDL_Renderer* renderer):
        width(width),
        height(height),
        renderer(renderer){
            m_world = new World(Environment(
                        TwoD::Vector(0.0f , -0.1f , 0.0f),
                        TwoD::Vector(-0.01f , 0.0f , 0.0f) 
                        ));
    }

    Canvas::~Canvas() {
        delete m_world;
    }


    void Canvas::draw() {
        m_world->draw(renderer);
    }

    void Canvas::update() {
        m_world->update();
    }

    void Canvas::write_pixle(int row , int col , const Color& color) {
        m_world->write_pixle(row , col , color);
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
        std::vector<std::vector<PixleData*>> pixles = m_world->get_pixles();

        int right_limit = width;
        int down_limit = height;

		for(unsigned int i = 0 ; i < down_limit ; i++) {
			current_line = "";
			for(unsigned int j = 0 ; j < right_limit ; j++) {

				Color current_color = pixles[j][i]->color;

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

    PixleData* Canvas::pixel_at(int row, int col) const {
        return m_world->pixel_at(row, col);
    }

};
