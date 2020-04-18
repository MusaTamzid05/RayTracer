#ifndef PIXLE_DATA_H
#define  PIXLE_DATA_H

#include <SDL2/SDL.h>
#include "color.h"

namespace Engine {

    struct PixleData {

        PixleData(int row , int col , const Color& color);
        void draw(SDL_Renderer* renderer);

        int row;
        int col;
        Color color;
    };

};
#endif
