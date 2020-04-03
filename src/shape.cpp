#include "shape.h"
#include <SFML/Graphics.hpp>

namespace Engine {
    
    Shape::Shape(float x , float y , float radius):
    pos(x , y , 0.0f){
        shape = new sf::CircleShape(radius);
        shape->setFillColor(sf::Color(0.0f , 0.0f , 100.0f));
        shape->setPosition(x , y);
    }

    Shape::~Shape() {
        delete shape;
    }

    void Shape::draw(sf::RenderWindow* window) {
        window->draw(*shape);
    }

    void Shape::update() {

    }
}
