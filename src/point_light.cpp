#include "point_light.h"
#include "color.h"
#include "point.h"

namespace Light {

    PointLight::PointLight(Engine::Color* color, TwoD::Point* position):
        intensity(color),
        position(position) {}


    bool PointLight::operator==(const Light::PointLight& point_light) {
        return *intensity == *point_light.intensity && *position == *point_light.position;
    }
};
