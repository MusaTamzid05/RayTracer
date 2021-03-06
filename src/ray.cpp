#include "ray.h"

namespace Light {

    Ray::Ray(const TwoD::Point& origin, const TwoD::Vector& direction):
        origin(origin),
        direction(direction) {}

    Ray::~Ray() {}


    TwoD::Point Ray::position(float distance) const {
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
        return transform(translation_matrix);
    }

    Ray Ray::scale(const TwoD::Point& point) {

        TwoD::Matrix4x4 scale_matrix = TwoD::Matrix4x4::scale(point);
        return transform(scale_matrix);

    }

    Ray Ray::transform(const TwoD::Matrix& matrix) const  {

        TwoD::Matrix src_matrix = matrix;
        TwoD::Tuple new_origin = src_matrix * origin;
        TwoD::Tuple new_direction = src_matrix * direction;

        return Ray(TwoD::Point::convert_to_point(new_origin), TwoD::Vector::convert_to_vector(new_direction));
    }

};
