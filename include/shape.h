#ifndef SHAPE_H
#define SHAPE_H

namespace sf {
    class CircleShape;
    class RenderWindow;
};


#include "vector.h"

namespace Engine {

    class Shape {

        public:
            Shape(float x , float y , float radius = 5.0f);
            virtual ~Shape();

            void draw(sf::RenderWindow* window);
            void update();

            void set_pos(const TwoD::Vector& pos) { this->pos = pos; }
            TwoD::Vector get_pos() { return pos; }

        private:

            sf::CircleShape* shape;
            TwoD::Vector pos;
    };
}
#endif
