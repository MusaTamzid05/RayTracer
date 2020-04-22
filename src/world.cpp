#include "world.h"
#include "shape.h"
#include "const.h"
#include "color.h"
#include "pixle_data.h"


namespace Engine {

    
    Environment::Environment(const TwoD::Vector& gravity , const TwoD::Vector& wind):
        gravity(gravity),
        wind(wind) {
        }


        
    World::World(const Environment& env):
    env(env){
        Engine::Shape* shape = new Engine::Shape(50.0f , 100.0f);
        TwoD::Point point = TwoD::Point(1.0f , 1.8f , 0.0f);
        TwoD::Tuple nor = point.normalize();
        nor *= 8.28;
        shape->set_velocity(TwoD::Point(nor.x , nor.y , nor.z));
        shapes.push_back(shape);
        
        clear_pixles();
    }

    World::~World() {

        for(Shape* shape : shapes)
            delete shape;
    }

    void World::draw(SDL_Renderer* renderer) {

        for(Shape* shape : shapes)
            shape->draw(renderer);
    }

    void World::update() {

        for(Shape* shape : shapes) {

            TwoD::Tuple new_pos = shape->get_pos() + shape->get_velocity();
            TwoD::Point new_pos_point(new_pos.x, new_pos.y, new_pos.z);

            std::cout << new_pos_point << "\n";

            TwoD::Tuple new_vel = shape->get_velocity() + env.gravity + env.wind;
            TwoD::Point new_vel_point(new_vel.x, new_vel.y, new_vel.z);

            shape->set_pos(new_pos_point);
            shape->set_velocity(new_vel_point);
        }

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

        std::cout << pixle_data.size() << " " <<  pixle_data[0].size() << "\n";

    }

    
    void World::write_pixle(int row , int col , const Color& color) {
        pixle_data[row][col] = new PixleData(row , col , color);

    }

};
