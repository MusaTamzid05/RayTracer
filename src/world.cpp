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
        Engine::Shape* shape = new Engine::Shape(Const::WIDTH / 2, Const::HEIGHT / 2);
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
