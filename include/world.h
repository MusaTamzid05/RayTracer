#ifndef WORLD_H
#define WORLD_H

#include "vector.h"
#include "point.h"
#include "color.h"
#include <vector>


#include <SDL2/SDL.h>


namespace Engine {

    struct PixleData;

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
            std::vector<std::vector<PixleData*>>  get_pixles();

            // write_pixle has more priority than shapes
            void write_pixle(int row , int col , const Color& color);

        private:


            std::vector<Shape*> shapes;
            Environment env;
            std::vector<std::vector<PixleData*>> pixle_data;

            // this used just for writing ppa file.
            void clear_pixles();

    };
};

#endif
