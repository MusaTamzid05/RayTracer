#include "computation.h"
#include "intersection.h"
#include "ray.h"
#include "sphere.h"

namespace Light {

    Computation::Computation(Intersection* intersection,
                Light::Ray* ray
            ):
        distance(intersection->distance),
        object(intersection->object){

            point = ray->position(distance);
            eye_vector = TwoD::Vector::convert_to_vector(ray->direction.negative());
            normal_vector = object->normal_at(point);
            
            TwoD::Vector vec1 = normal_vector;
            TwoD::Vector vec2 = eye_vector;

            if(normal_vector.dot(eye_vector) < 0.0f)
                inside = true;
            else
                inside = false;

        }

};
