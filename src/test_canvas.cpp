#include "test_canvas.h"
#include "canvas.h"
#include "operation.h"

namespace Testing {

    void TestCanvas::setUp() {

    }

    void TestCanvas::tearDown() {

    }


    void TestCanvas::testPPMHeader() {

        std::string canvas_path = "./results.ppm";

        Engine::Canvas canvas(5 , 3 , nullptr);
        std::vector<std::string> lines;
        canvas.save(canvas_path);

        lines = Operation::read_lines_from(canvas_path);
    

        CPPUNIT_ASSERT(lines[0] == "P3");
        CPPUNIT_ASSERT(lines[1] == "5 3");
        CPPUNIT_ASSERT(lines[2] == "255");
    }

    void TestCanvas::testPPMData() {


        std::string canvas_path = "./results.ppm";

        Engine::Canvas canvas(5 , 3 , nullptr);
        canvas.write_pixle(0 , 0 , Engine::Color(1.5f , 0.0f , 0.0f));
        canvas.write_pixle(2 , 1 , Engine::Color(0.0f , 0.5f , 0.0f));
        canvas.write_pixle(4 , 2 , Engine::Color(-0.5f , 0.0f , 1.0f));
        std::vector<std::string> lines;
        canvas.save(canvas_path);

        lines = Operation::read_lines_from(canvas_path);
    
        CPPUNIT_ASSERT(Operation::trim(lines[3]) == "255 0 0 0 0 0 0 0 0 0 0 0 0 0 0");
        CPPUNIT_ASSERT(Operation::trim(lines[4]) == "0 0 0 0 0 0 0 127 0 0 0 0 0 0 0");
        CPPUNIT_ASSERT(Operation::trim(lines[5]) == "0 0 0 0 0 0 0 0 0 0 0 0 0 0 255");
    }

    
    
}
