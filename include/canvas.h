#ifndef CANVAS_H
#define CANVAS_H

#include <SDL2/SDL.h>
#include "color.h"
#include "pixle_data.h"
#include <vector>

namespace Engine {


    class Canvas {

        public:
            Canvas(int width , int height , SDL_Renderer* renderer);
            virtual ~Canvas();

            void draw();
            void write_pixle(int row , int col , const Color& color);

        private:

            int width;
            int height;

            SDL_Renderer* renderer;
            std::vector<PixleData> pixle_data;
    };
};

#endif
