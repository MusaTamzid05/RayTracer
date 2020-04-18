#include "pixle_data.h"
#include "operation.h"

namespace Engine {

    PixleData::PixleData(int row , int col , const Color& color):
        row(row),
        col(col),
        color(color){

    }

    void PixleData::draw(SDL_Renderer* renderer) {

        SDL_SetRenderDrawColor(renderer,
                Operation::scale_int(color.red() , 255),
                Operation::scale_int(color.green() , 255),
                Operation::scale_int(color.blue() , 255),
                255
                );
        SDL_RenderDrawPoint(renderer , row , col);
        SDL_SetRenderDrawColor(renderer , 0 , 0 , 0 , 0);
    }
};
