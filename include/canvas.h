#ifndef CANVAS_H
#define CANVAS_H

#include <SDL2/SDL.h>

namespace Engine {

    class Canvas {

        public:
            Canvas(int width , int height , SDL_Renderer* renderer);
            virtual ~Canvas();

            void render();

        private:

            int width;
            int height;

            void init();

            Uint32* pixels;
            SDL_Renderer* renderer;
            SDL_Texture* m_texture;
    };
};

#endif
