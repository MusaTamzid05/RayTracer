#ifndef INTERSECTION_H
#define INTERSECTION_H

#include <vector>

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

            bool operator==(const Intersection& intersection);
            void operator=(const Intersection& intersection);

    };

    class IntersectionContainer {

        public:

            IntersectionContainer();
            virtual ~IntersectionContainer() {}

            void add(const Intersection& intersection);
            Intersection get(int index);

            int size() { return intersections.size(); }
            Intersection hit();


        private:

            std::vector<Intersection> intersections;



    };

};

#endif
