#ifndef APP_H
#define APP_H

#include <string>
#include <vector>
#include <SDL2/SDL.h>



namespace Engine {

    class Shape;
    class Canvas;

    class App {

        public:
            App(const std::string& title = "App" , float frame_rate = 30.0f ,  int width = 640 , int  height = 480);
            virtual ~App();

            void run();

        private:

            void handle_event();
            void render();
            void update();

            int width;
            int height;

            SDL_Window* m_window;
            SDL_Renderer* m_renderer;
            SDL_Event m_event;

            Canvas* m_canvas;

            bool running;

    };
};
#endif
