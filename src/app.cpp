#include "app.h"
#include "shape.h"
#include "canvas.h"
#include "fps.h"
#include "const.h"

namespace Engine {

    App::App(const std::string& title , float frame_rate):
        width(Const::WIDTH),
        height(Const::HEIGHT),
        m_fps(new FrameRateSecond()){
            SDL_Init(SDL_INIT_VIDEO);
            SDL_CreateWindowAndRenderer(width , height , 0 , &m_window, &m_renderer);
            m_canvas = new Engine::Canvas(width , height , m_renderer);
            running = true;
            
        }

    App::~App() {

        delete m_fps;
        delete m_canvas;
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();

    }

    void App::run() {

        while(running) {
            m_fps->update_timer();
            handle_event();
            update();
            render();
            m_fps->handle_fps();
        }
    }

    void App::update() {
        m_canvas->update();
    }

    void App::handle_event() {

        while(SDL_PollEvent(&m_event)) {
            switch(m_event.type) {
                case SDL_QUIT:
                    running = false;
                    break;

                case SDL_KEYDOWN:
                    if(m_event.key.keysym.sym == SDLK_ESCAPE)
                        running = false;
                    break;

                    
            }
        }

    }

    void App::render() {
        SDL_SetRenderDrawColor(m_renderer , 0 , 0 , 0 , 0);

        SDL_RenderClear(m_renderer);
        m_canvas->draw();
        SDL_RenderPresent(m_renderer);
    }
}
