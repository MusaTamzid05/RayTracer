#include "canvas.h"
#include <iostream>
#include "operation.h"
#include "world.h"

namespace Engine {

    Canvas::Canvas(int width , int height , SDL_Renderer* renderer):
        width(width),
        height(height),
        renderer(renderer){
            m_world = new World(Environment(
                        TwoD::Vector(0.0f , -0.1f , 0.0f),
                        TwoD::Vector(-0.01f , 0.0f , 0.0f) 
                        ));
    }

    Canvas::~Canvas() {
        delete m_world;
    }


    void Canvas::draw() {
        m_world->draw(renderer);
    }

    void Canvas::update() {
        m_world->update();
    }

    void Canvas::write_pixle(int row , int col , const Color& color) {
    }

};
