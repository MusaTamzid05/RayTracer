#ifndef SHAPE_H
#define SHAPE_H

namespace sf {
    class CircleShape;
    class RenderWindow;
};


#include "point.h"

namespace Engine {

    class Shape {

        public:
            Shape(float x , float y , float radius = 5.0f);
            virtual ~Shape();

            void draw(sf::RenderWindow* window);
            void update();

            void set_pos(const TwoD::Point& pos);
            TwoD::Point get_pos() { return pos; }

        private:

            sf::CircleShape* shape;
            TwoD::Point pos;
    };
}
#endif
