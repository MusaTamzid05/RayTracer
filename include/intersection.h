#ifndef INTERSECTION_H
#define INTERSECTION_H

namespace Light {
    class Sphere;
};

namespace Light {

    class Intersection {
        public:
            Intersection(float distance, Light::Sphere* sphere);
            virtual ~Intersection() {}


            Light::Sphere* sphere;
            float distance;
    };

};

#endif
