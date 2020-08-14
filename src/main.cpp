#include "unit_test.h"
#include "app.h"


#include "point.h"
#include "vector.h"
#include "ray_world.h"
#include "ray.h"
#include "sphere.h"
#include "material.h"
#include "computation.h"
#include "point_light.h"

int main_app()  {

    Engine::App app;
    app.run();
        
    return 0;
}

int run_test() {
    return Testing::run_test();
}

int main(int argc , char** argv) {
    return run_test();
}
