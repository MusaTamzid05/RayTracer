#include "intersection.h"
#include "sphere.h"
#include <algorithm>

namespace Light {
    Intersection::Intersection(float distance, Light::Sphere* object):
        distance(distance),
        object(object){

    }

    IntersectionContainer::IntersectionContainer() {

    }

    void IntersectionContainer::add(const Intersection& intersection) {

        intersections.push_back(intersection);
        std::sort(std::begin(intersections),
                std::end(intersections),
                [](Intersection data1, Intersection data2) {
                   return data1.distance < data2.distance;
                }
                );
    }

    Intersection IntersectionContainer::get(int index) {

        if(index < 0 || index >= intersections.size()) {
            std::cerr << "intersection index out of range!!\n";
            return Intersection(-0.0f, nullptr);
        }

        return intersections[index];
    }
};


