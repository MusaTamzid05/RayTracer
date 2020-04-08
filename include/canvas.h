#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include "color.h"

namespace Engine {

    class Canvas {

        public:
            Canvas(int width , int height);
            virtual ~Canvas() {}
            void show_pixles();

            Color get_pixle(int row , int col) const { return pixles[row][col]; }

            void save(const std::string& save_path = "./result.ppm");

        private:

            int width;
            int height;

            void init_pixles();

            std::vector<std::vector<Color>> pixles;

    };
};

#endif
