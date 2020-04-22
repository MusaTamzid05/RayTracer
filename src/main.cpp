#include "unit_test.h"
#include "app.h"
#include "color.h"
#include <iostream>
#include "world.h"
#include "canvas.h"

int main_app()  {

    /*
    Engine::App app;
    app.run();
    */

    Engine::Canvas* canvas = new Engine::Canvas(5 , 3 , nullptr);
    canvas->save("./result.txt");


    return 0;
}

int run_test() {
    return Testing::run_test();
}

int main(int argc , char** argv) {
    return run_test();
}
