#include "material.h"

namespace Light {

    Material::Material():
        color(1.0f, 1.0f, 1.0f),
        ambient(0.1f),
        diffuse(0.9f),
        specular(0.9f),
        shininess(200.0f) {}


    bool Material::operator==(const Material& material) {
        return color == material.color &&
            ambient == material.ambient &&
            diffuse == material.diffuse &&
            specular == material.specular &&
            shininess == material.shininess;
    }
};
