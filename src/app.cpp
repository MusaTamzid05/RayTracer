#include "app.h"
#include "shape.h"
#include <SFML/Graphics.hpp>

namespace Engine {

    App::App(const std::string& title , int width , int height):
        width(width),
        height(height) {
            m_window = new sf::RenderWindow(sf::VideoMode(width , height) , title);
            shapes.push_back(new Shape(50.0f , 350.0f));
        }

    App::~App() {
        delete m_window;
    }

    void App::run() {


        while(m_window->isOpen()) {
            handle_event();
            update();
            render();
        }
    }

    void App::update() {

        for(Shape* shape : shapes)
            shape->update();

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

        for(Shape* shape : shapes)
            shape->draw(m_window);

        m_window->display();
    }
}
