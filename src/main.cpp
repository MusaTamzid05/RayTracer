#include "unit_test.h"
#include "app.h"
#include "sphere.h"
#include "ray.h"
#include "intersection.h"




int main_app()  {

    //Engine::App app;
    //app.run();

    Light::Ray ray(TwoD::Point(0.0f, 0.0f, -5.0f), TwoD::Vector(0.0f, 0.0f, 1.0f));
    Light::Sphere sphere;
    std::vector<Light::Intersection> intersections = sphere.intersect(ray);

    std::cout << intersections.size() << "\n";
    std::cout << intersections[0].distance << "\n";
    std::cout << intersections[1].distance << "\n";

    return 0;
}

int run_test() {
    return Testing::run_test();
}

int main(int argc , char** argv) {
    return main_app();
}
