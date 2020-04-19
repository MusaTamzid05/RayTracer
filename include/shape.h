#ifndef SHAPE_H
#define SHAPE_H

#include <SDL2/SDL.h>
#include "point.h"
#include "color.h"


namespace Engine {
    struct PixleData;

    class Shape {

        public:
            Shape(float x , float y , float z = 0.0f);
            virtual ~Shape();

            void draw(SDL_Renderer* renderer);
            void update();

            void set_color(const Color& color);

            void set_pos(const TwoD::Point& pos);
            TwoD::Point get_pos() { return pos; }

            void set_velocity(const TwoD::Point& velocity) { this->velocity = velocity; }
            TwoD::Point get_velocity() { return velocity; }

        private:

            TwoD::Point pos;
            TwoD::Point velocity;

            Color m_color;
            PixleData* pixle;
    };
}
#endif
