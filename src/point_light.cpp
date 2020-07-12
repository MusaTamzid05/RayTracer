#include "point_light.h"
#include "color.h"
#include "point.h"

namespace Light {

    PointLight::PointLight(Engine::Color* color, TwoD::Point* position):
        intensity(color),
        position(position) {}
};
