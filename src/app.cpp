#include "app.h"
#include "shape.h"
#include "canvas.h"

namespace Engine {

    App::App(const std::string& title , float frame_rate ,  int width , int height):
        width(width),
        height(height),
    m_canvas(nullptr){
            SDL_Init(SDL_INIT_VIDEO);
            SDL_CreateWindowAndRenderer(width , height , 0 , &m_window, &m_renderer);
            running = true;
        }

    App::~App() {

        delete m_canvas;
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();

    }

    void App::run() {

        while(running) {
            handle_event();
            update();
            render();
        }
    }

    void App::update() {
    }

    void App::handle_event() {

        if(SDL_PollEvent(&m_event) && m_event.type == SDL_QUIT)
            running = false;
    }

    void App::render() {
        SDL_RenderClear(m_renderer);

        SDL_RenderPresent(m_renderer);
    }
}
