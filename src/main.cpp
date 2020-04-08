#include "unit_test.h"
#include "app.h"
#include "tuple.h"
#include "point.h"
#include "operation.h"
#include "canvas.h"
#include "vector.h"
#include <iostream>

int main_app()  {

    Engine::Canvas canvas(5, 3);
    canvas.save("ss\n");

    return 0;
}

int run_test() {
    return Testing::run_test();
}

int main(int argc , char** argv) {
    return run_test();
}
