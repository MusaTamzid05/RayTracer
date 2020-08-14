#ifndef MATERIAL_H
#define MATERIAL_H

#include "vector.h"
#include "color.h"

namespace TwoD {
    struct Point;
};

namespace Light {

    struct PointLight;
    struct Material {

        Engine::Color color;
        float ambient;
        float diffuse;
        float specular;
        float shininess;

        bool operator==(const Material& material);
        Material();


        Engine::Color lighting(const Light::PointLight* point_light,
            const TwoD::Point& point,
            const TwoD::Vector& eye_vector,
            const TwoD::Vector& normal_vector) const;

    };
};

#endif
