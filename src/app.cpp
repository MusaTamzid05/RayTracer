#include "app.h"
#include "shape.h"
#include "canvas.h"
#include "fps.h"

namespace Engine {

    App::App(const std::string& title , float frame_rate ,  int width , int height):
        width(width),
        height(height),
        m_fps(new FrameRateSecond()){
            SDL_Init(SDL_INIT_VIDEO);
            SDL_CreateWindowAndRenderer(width , height , 0 , &m_window, &m_renderer);
            m_canvas = new Engine::Canvas(width , height , m_renderer);
            running = true;
            
            for(unsigned int i = 0 ; i < width ; i++) {

                m_canvas->write_pixle(i , i , Engine::Color(1.0f , 0.0f , 0.0f));

                for(unsigned int j = 0 ; j < 5 ; j++) {

                    m_canvas->write_pixle(i , height - j  , Engine::Color(0.0f , 0.0f , 1.0f));
                    m_canvas->write_pixle(i ,  j  , Engine::Color(0.0f , 0.0f , 1.0f));
                }
            }

            for(unsigned int i = 0 ; i < height ; i++) {
                for (unsigned int j = 0 ; j < 5; j++) {
                    m_canvas->write_pixle(j , i , Engine::Color(0.0f , 1.0f , 0.0f));
                    m_canvas->write_pixle(width - (j + 1) , i , Engine::Color(0.0f , 1.0f , 0.0f));
                }
            }
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

        if(SDL_PollEvent(&m_event) && m_event.type == SDL_QUIT)
            running = false;
    }

    void App::render() {
        SDL_SetRenderDrawColor(m_renderer , 0 , 0 , 0 , 0);

        SDL_RenderClear(m_renderer);
        m_canvas->draw();
        SDL_RenderPresent(m_renderer);
    }
}
