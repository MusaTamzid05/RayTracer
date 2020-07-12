#include "point_light.h"
#include "color.h"
#include "point.h"

namespace Light {

    PointLight::PointLight(Engine::Color* color, TwoD::Point* position):
        color(color),
        position(position) {}
};
