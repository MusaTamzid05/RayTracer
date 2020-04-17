#ifndef APP_H
#define APP_H

#include <string>
#include <vector>

namespace sf {
    class RenderWindow;
};

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

            sf::RenderWindow* m_window;
            Canvas* m_canvas;

    };
};
#endif
