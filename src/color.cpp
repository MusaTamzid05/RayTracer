#include "color.h"

namespace Engine {
    Color Color::hadamard_product(const Color& color) const {
        return Color(red() * color.red() , green() * color.green() , blue() * color.blue());
    }

    Color Color::convert_to_color(const Tuple& data) {
        return Color(data.x, data.y, data.z);
    }

};
