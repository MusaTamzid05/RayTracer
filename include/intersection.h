#ifndef INTERSECTION_H
#define INTERSECTION_H

namespace Light {
    class Sphere;
};

namespace Light {

    class Intersection {
        public:
            Intersection(float distance,Light::Sphere* object);
            virtual ~Intersection() {}

            Light::Sphere* object;
            float distance;
    };

};

#endif
