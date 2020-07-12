#ifndef MATERIAL_H
#define MATERIAL_H

#include "vector.h"
#include "color.h"

namespace Light {
    struct Material {

        Engine::Color color;
        float ambient;
        float diffuse;
        float specular;
        float shininess;

        Material();

    };
};

#endif
