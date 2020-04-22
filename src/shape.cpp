#include "shape.h"
#include "pixle_data.h"
#include <SFML/Graphics.hpp>

#include "const.h"

namespace Engine {
    
    Shape::Shape(float x , float y , float z):
        pos(x , y , z),
        velocity(0.0f , 0.0f , 0.0f),
        m_color(1.0f , 0.0f , 0.0f){
            pixle = new PixleData(x , y , m_color);
    }

    Shape::~Shape() {
        delete pixle;
    }

    void Shape::draw(SDL_Renderer* renderer) {
        pixle->draw(renderer);
    }

    void Shape::update() {

    }
    
    void Shape::set_pos(const TwoD::Point& pos) {
        this->pos = pos;
        pixle->row = pos.x;
        pixle->col = Const::HEIGHT - pos.y;
    }
    
    void Shape::set_color(const Color& color) {
        m_color = color;
        pixle->color = color;
    }

    PixleData* Shape::get_pixle() {
        return pixle;
    }

}
