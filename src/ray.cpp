#include "ray.h"

namespace Light {

    Ray::Ray(const TwoD::Point& origin, const TwoD::Vector& direction):
        origin(origin),
        direction(direction) {}

    Ray::~Ray() {}


    TwoD::Point Ray::position(float distance) {
        TwoD::Tuple new_direction = direction;
        TwoD::Tuple result = origin + new_direction * distance;
        return TwoD::Point::convert_to_point(result);
    }

    std::ostream& operator<<(std::ostream& out , const Ray& ray) {
        out << "Origin : " << ray.origin << "\n";
        out << "Direction : " << ray.direction;

        return out;
    }


    Ray Ray::translation(const TwoD::Point& point) {

        TwoD::Matrix4x4 translation_matrix = TwoD::Matrix4x4::translation(point);
        TwoD::Tuple new_origin = translation_matrix * origin;
        TwoD::Tuple new_direction = translation_matrix * direction;

        return Ray(TwoD::Point::convert_to_point(new_origin), TwoD::Vector::convert_to_vector(new_direction));
    }

    Ray Ray::scale(const TwoD::Point& point) {

        TwoD::Matrix4x4 scale_matrix = TwoD::Matrix4x4::scale(point);

        TwoD::Tuple new_origin = scale_matrix * origin;
        TwoD::Tuple new_direction = scale_matrix * direction;

        return Ray(TwoD::Point::convert_to_point(new_origin), TwoD::Vector::convert_to_vector(new_direction));

    }

};
