#include "material.h"
#include "point_light.h"
#include "point.h"
#include <math.h>

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


    TwoD::Vector Material::lighting(const Light::PointLight* point_light,
            TwoD::Point& point,
            TwoD::Vector& eye_vector,
            TwoD::Vector& normal_vector
            ) {


        TwoD::Vector diffuse_vector;
        TwoD::Vector specular_vector;
        // my god !!, this is just bad c++,
        // #TODO: learn c++ !!

        TwoD::Tuple effective_color_tuple  = color * *point_light->intensity;
        Engine::Color effective_color = Engine::Color::convert_to_color(effective_color_tuple);

        TwoD::Tuple dir_tuple =  *point_light->position - point;
        TwoD::Tuple dir_tuple_result =  dir_tuple.normalize();
        TwoD::Vector light_vector =  TwoD::Vector::convert_to_vector(dir_tuple_result);


        TwoD::Tuple ambient_tuple = effective_color.mul(ambient);
        TwoD::Vector ambient_vector = TwoD::Vector::convert_to_vector(ambient_tuple);

        float light_dot_normal = light_vector.dot(normal_vector);

        if(light_dot_normal < 0)  {
            // light vector is in the other side
            // of the surface.
    
            diffuse_vector = TwoD::Vector(0.0f, 0.0f, 0.0f);
            specular_vector = TwoD::Vector(0.0f, 0.0f, 0.0f);

        } else {
            TwoD::Tuple diffuse_tuple =  effective_color.mul(diffuse * light_dot_normal);
            diffuse_vector =  TwoD::Vector::convert_to_vector(diffuse_tuple);

            TwoD::Vector reflect_vector = light_vector.reflect(normal_vector);
            TwoD::Vector reflect_vector_negative = TwoD::Vector::convert_to_vector(reflect_vector.negative());
            float reflect_dot_eye =  reflect_vector_negative.dot(eye_vector);

            if(reflect_dot_eye <= 0.0f) 
                specular_vector = TwoD::Vector(0.0f, 0.0f, 0.0f);
            else {
                float factor = pow(reflect_dot_eye, shininess);
                TwoD::Tuple specular_tuple = point_light->intensity->mul(specular * factor);
                specular_vector = TwoD::Vector::convert_to_vector(specular_tuple);
            }

        }

        return TwoD::Vector::convert_to_vector(ambient_vector + diffuse_vector + specular_vector);

    }

};
