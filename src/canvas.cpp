#include "canvas.h"
#include <iostream>

namespace Engine {

    Canvas::Canvas(int width , int height , SDL_Renderer* renderer):
        width(width),
        height(height),
        renderer(renderer)
    {
        init();
    }

    Canvas::~Canvas() {
        delete []pixels;
        SDL_DestroyTexture(m_texture);
    }

    void Canvas::init() {

        pixels = new Uint32[width * height];
        memset(pixels , 255 , width * height * sizeof(Uint32));
    }

    void Canvas::render() {
        SDL_UpdateTexture(m_texture , nullptr , pixels , width * sizeof(Uint32));
        SDL_RenderCopy(renderer , m_texture , nullptr , nullptr);
    }

};
