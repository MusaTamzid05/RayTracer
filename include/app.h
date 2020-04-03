#ifndef APP_H
#define APP_H

#include <string>

namespace sf {
    class RenderWindow;
};

namespace Engine {

    class App {

        public:
            App(const std::string& title = "App" , int width = 640 , int  height = 480);
            virtual ~App();

            void run();

        private:

            void handle_event();
            void render();

            int width;
            int height;

            sf::RenderWindow* m_window;
    };
};
#endif
