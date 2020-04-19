#ifndef WORLD_H
#define WORLD_H

#include "vector.h"
#include "point.h"


#include <SDL2/SDL.h>


namespace Engine {

    struct Environment {
        TwoD::Vector gravity;
        TwoD::Vector wind;

        Environment(const TwoD::Vector& gravity , const TwoD::Vector& wind);
    };

    class Shape;

    class World {

        public:

            World(const Environment& env);
            virtual ~World();

            void draw(SDL_Renderer* renderer);
            void update();

        private:

            Shape* m_shape;
            Environment env;

    };
};

#endif
