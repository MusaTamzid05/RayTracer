#ifndef INTERSECTION_H
#define INTERSECTION_H

#include <vector>

namespace Light {
    class Sphere;
};

namespace Light {

    class Intersection {
        public:
            Intersection(float distance, const Light::Sphere* object);
            virtual ~Intersection() {}

            const Light::Sphere* object;
            float distance;

            bool is_hit();

            bool operator==(const Intersection& intersection);
            void operator=(const Intersection& intersection);

    };

    class IntersectionContainer {

        public:

            IntersectionContainer();
            virtual ~IntersectionContainer() {}

            void add(const Intersection& intersection);
            Intersection get(int index) const;

            int size() { return intersections.size(); }
            Intersection hit();


            void operator+=(const IntersectionContainer& new_container);

        private:

            std::vector<Intersection> intersections;



    };

};

#endif
