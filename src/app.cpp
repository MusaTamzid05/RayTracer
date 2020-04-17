#include "app.h"
#include "shape.h"
#include "canvas.h"
#include <SFML/Graphics.hpp>

namespace Engine {

    App::App(const std::string& title , float frame_rate ,  int width , int height):
        width(width),
        height(height) {
            m_window = new sf::RenderWindow(sf::VideoMode(width , height) , title);
            m_window->setFramerateLimit(frame_rate);
            m_canvas = new Canvas(width , height);
        }

    App::~App() {
        delete m_window;
        delete m_canvas;
    }

    void App::run() {


        while(m_window->isOpen()) {
            handle_event();
            update();
            render();
        }
    }

    void App::update() {
    }

    void App::handle_event() {

        sf::Event event;

        while(m_window->pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                m_window->close();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                m_window->close();
        }
    }

    void App::render() {

        m_window->clear(sf::Color(100 , 0 , 0));
        m_canvas->draw(m_window);
        m_window->display();
    }
}
