#include "computation.h"
#include "intersection.h"
#include "ray.h"
#include "sphere.h"

namespace Light {

    Computation::Computation(const Intersection* intersection,
                const Light::Ray* ray
            ):
        distance(intersection->distance),
        object(intersection->object){

            point = ray->position(distance);
            eye_vector = TwoD::Vector::convert_to_vector(ray->direction.negative());
            normal_vector = object->normal_at(point);
            

            if(normal_vector.dot(eye_vector) < 0.f) {
                inside = true;
                normal_vector = TwoD::Vector::convert_to_vector(normal_vector.negative());
            }
            else
                inside = false;


        }

};
