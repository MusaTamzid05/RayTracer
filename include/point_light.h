#ifndef POINT_LIGHT_H
#define POINT_LIGHT_H


namespace Engine {
    struct Color;
};

namespace TwoD {
    struct Point;
};


namespace Light {

    struct PointLight {

        PointLight(Engine::Color* color = nullptr,TwoD::Point* position = nullptr);

        Engine::Color* intensity;
        TwoD::Point* position;

    };
};
#endif
