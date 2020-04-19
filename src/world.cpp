#include "world.h"
#include "shape.h"


namespace Engine {

    
    Environment::Environment(const TwoD::Vector& gravity , const TwoD::Vector& wind):
        gravity(gravity),
        wind(wind) {
        }


        
    World::World(const Environment& env):
    env(env){
        m_shape = new Engine::Shape(50.0f , 100.0f);
        TwoD::Point point = TwoD::Point(1.0f , 1.8f , 0.0f);
        TwoD::Tuple nor = point.normalize();
        nor *= 8.28;
        m_shape->set_velocity(TwoD::Point(nor.x , nor.y , nor.z));
    }

    World::~World() {
        delete m_shape;
    }

    void World::draw(SDL_Renderer* renderer) {
        m_shape->draw(renderer);
    }

    void World::update() {

        TwoD::Tuple new_pos = m_shape->get_pos() + m_shape->get_velocity();
        TwoD::Point new_pos_point(new_pos.x, new_pos.y, new_pos.z);

        std::cout << new_pos_point << "\n";

        TwoD::Tuple new_vel = m_shape->get_velocity() + env.gravity + env.wind;
        TwoD::Point new_vel_point(new_vel.x, new_vel.y, new_vel.z);

        m_shape->set_pos(new_pos_point);
        m_shape->set_velocity(new_vel_point);

    }

};
