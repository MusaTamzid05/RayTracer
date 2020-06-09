#include "world.h"
#include "shape.h"
#include "const.h"
#include "color.h"
#include "pixle_data.h"
#include "matrix.h"
#include <math.h>


namespace Engine {

    
    Environment::Environment(const TwoD::Vector& gravity , const TwoD::Vector& wind):
        gravity(gravity),
        wind(wind) {
        }


        
    World::World(const Environment& env):
    env(env){
    
        clear_pixles();
        std::vector<TwoD::Point> clock_points = get_clock_points(160.0f, TwoD::Point(Const::WIDTH / 2, Const::HEIGHT / 2, 0.0f));

        for (TwoD::Point point : clock_points)
                shapes.push_back(new Engine::Shape(point.x, point.y, point.z));


        std::cout << shapes.size() << "\n";
    }

    World::~World() {

        for(Shape* shape : shapes)
            delete shape;
    }

    std::vector<TwoD::Point> World::get_clock_points(float radius, const TwoD::Point& center) {

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

        return points;

    }



    void World::draw(SDL_Renderer* renderer) {

        for(Shape* shape : shapes)
            shape->draw(renderer);
    }

    void World::update() {
    }

    
    std::vector<std::vector<PixleData*>> World::get_pixles() {
        clear_pixles();

        for(Shape* shape : shapes) {
            PixleData* current_pixle = shape->get_pixle();
            pixle_data[current_pixle->row][current_pixle->col] = current_pixle;
        }

        return pixle_data;

    }

    void World::clear_pixles() {

        int right_limit = Const::WIDTH;
        int down_limit = Const::HEIGHT;

        for(unsigned int i = 0 ; i < right_limit; i++) {
            std::vector<PixleData*> current_data;
            for(unsigned int j = 0 ; j < down_limit ; j++) {
                current_data.push_back(new PixleData(i , j , Engine::Color(0.0f , 0.0f , 0.0f)));
            }

            pixle_data.push_back(current_data);
        }


    }

    
    void World::write_pixle(int row , int col , const Color& color) {
        pixle_data[row][col] = new PixleData(row , col , color);

    }

};
