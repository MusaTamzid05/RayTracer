#ifndef CANVAS_H
#define CANVAS_H

#include <SDL2/SDL.h>
#include "color.h"
#include <vector>

namespace Engine {

    class World;

    class Canvas {

        public:
            Canvas(int width , int height , SDL_Renderer* renderer);
            virtual ~Canvas();

            void draw();
            void write_pixle(int row , int col , const Color& color);

            void update();

        private:

            int width;
            int height;

            SDL_Renderer* renderer;
            World* m_world;
    };
};

#endif
