#include "canvas.h"
#include <iostream>
#include "operation.h"

namespace Engine {

    Canvas::Canvas(int width , int height , SDL_Renderer* renderer):
        width(width),
        height(height),
        renderer(renderer)
    {
    }

    Canvas::~Canvas() {
    }


    void Canvas::draw() {

        for(PixleData& data : pixle_data)
            data.draw(renderer);

    }

    void Canvas::write_pixle(int row , int col , const Color& color) {
        pixle_data.push_back(PixleData(row , col , color));
    }

};
