#include "intersection.h"
#include "sphere.h"
#include <algorithm>

namespace Light {
    Intersection::Intersection(float distance, const Light::Sphere* object):
        distance(distance),
        object(object){

    }

    bool Intersection::operator==(const Intersection& intersection) {
        return distance == intersection.distance && object == intersection.object;
    }

    

    void Intersection::operator=(const Intersection& intersection) {
        distance = intersection.distance;
        object = intersection.object;
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

    
    void IntersectionContainer::operator+=(const IntersectionContainer& new_container) {

        for(Intersection intersection : new_container.intersections)
            add(intersection);

    }

    Intersection IntersectionContainer::get(int index) const {

        if(index < 0 || index >= intersections.size()) {
            std::cerr << "intersection index out of range!!\n";
            return Intersection(-0.0f, nullptr);
        }

        return intersections[index];
    }


    Intersection IntersectionContainer::hit() {

        Intersection hit_intersection(100000.0f, nullptr);
        
        for(Intersection current_intersection : intersections) {

            if(current_intersection.distance < 0)
                continue;

            if(current_intersection.distance < hit_intersection.distance) 
                hit_intersection = current_intersection;
        }

        return hit_intersection;
    }
};


