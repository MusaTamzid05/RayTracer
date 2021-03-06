#include "world.h"
#include "shape.h"
#include "const.h"
#include "color.h"
#include "pixle_data.h"
#include "ray.h"
#include "sphere.h"
#include "intersection.h"
#include "material.h"
#include "point_light.h"


namespace Engine {

    
    Environment::Environment(const TwoD::Vector& gravity , const TwoD::Vector& wind):
        gravity(gravity),
        wind(wind) {
        }


        
    World::World(const Environment& env):
    env(env){
        sphere = new Light::Sphere();
        sphere->material = new Light::Material();
        sphere->material->color = Engine::Color(1, 0.2f, 1.0f);

        light = new Light::PointLight(
                new Engine::Color(1.0f, 1.0f, 1.0f),
                new TwoD::Point(-10.0f, -10.0f, -10.0f)
                );

        clear_pixles();
        init_world();

    }

    World::~World() {

    }

    void World::draw(SDL_Renderer* renderer) {

        for(unsigned int y = 0; y < Const::HEIGHT; y++) {
            for(unsigned int x = 0; x < Const::WIDTH; x++)
                pixle_data[x][y]->draw(renderer);
        }
    }

    void World::update() {
    }

    
    std::vector<std::vector<PixleData*>> World::get_pixles() {
        clear_pixles();

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

    void World::init_world() {

        TwoD::Point ray_origin = TwoD::Point(0.0f, 0.0f, -5.0f);
        float wall_z = 10.0f;
        float wall_size = 7.0f;

        float pixel_size = wall_size / Const::WIDTH;
        float half = wall_size / 2.0;

        std::cout << pixel_size << "\n";
        std::cout << half << "\n";

        for(unsigned int y = 0 ; y < Const::HEIGHT; y++) {
            for(unsigned int x = 0 ; x < Const::WIDTH; x++) {
                float world_y = half - pixel_size * y;
                float world_x = -half + pixel_size * x;
                TwoD::Point position(world_x, world_y, wall_z);

                TwoD::Tuple direction_tuple = position - ray_origin;
                TwoD::Tuple direction_tuple_norm = direction_tuple.normalize();
                TwoD::Vector direction = TwoD::Vector::convert_to_vector(direction_tuple_norm);

                Light::Ray ray(ray_origin, direction);
                Light::IntersectionContainer container = sphere->intersect(ray);

                Light::Intersection result = container.hit();

                if(result.object != nullptr) {
                    TwoD::Point point =  ray.position(result.distance);
                    TwoD::Vector normal = result.object->normal_at(point);
                    TwoD::Vector eye = TwoD::Vector::convert_to_vector(ray.direction.negative());
                    Engine::Color color = result.object->material->lighting(light, point, eye, normal);

                    write_pixle(x, y, color);
                }

            }

        }

        std::cout << "World is created.\n";
    }


    PixleData* World::pixel_at(int row, int col) const {
        return pixle_data[row][col];
    }

};
