#include "unit_test.h"
#include "app.h"
#include "color.h"
#include <iostream>

int main_app()  {

    Engine::App app;
    app.run();

    return 0;
}

int run_test() {
    return Testing::run_test();
}

int main(int argc , char** argv) {
    return main_app();
}
