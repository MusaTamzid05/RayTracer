#include "unit_test.h"
#include "app.h"
#include "color.h"
#include "canvas.h"
#include <iostream>
#include "operation.h"

int main_app()  {

    Engine::Canvas canvas(640, 480);
    canvas.write_pixle(0 , 0 , Engine::Color(1.5f , 0.0f , 0.0f));
    canvas.write_pixle(2 , 1 , Engine::Color(0.0f , 0.5f , 0.0f));
    canvas.write_pixle(4 , 2 , Engine::Color(-0.5f , 0.0f , 1.0f));
    canvas.save("./result.txt");

    return 0;
}

int run_test() {
    return Testing::run_test();
}

int main(int argc , char** argv) {
    return main_app();
}
