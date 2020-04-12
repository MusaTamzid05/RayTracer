#include "test_canvas.h"
#include "canvas.h"
#include "operation.h"

namespace Testing {

    void TestCanvas::setUp() {

    }

    void TestCanvas::tearDown() {

    }

    void TestCanvas::testCanvasIsBlackAtInit() {

        int width = 640;
        int height = 480;

        Engine::Canvas canvas(width, height);

        for(unsigned int row = 0 ; row < height ; row++) {
            for(unsigned int col = 0 ; col < width ; col++) {
                Engine::Color color = canvas.get_pixle(row , height);
                CPPUNIT_ASSERT(canvas.get_pixle(row , height) == Engine::Color(0.0f , 0.0f , 0.0f));
            }
        }

    }

    void TestCanvas::testPPMHeader() {

        std::string canvas_path = "./results.ppm";

        Engine::Canvas canvas(5 , 3);
        std::vector<std::string> lines;
        canvas.save(canvas_path);

        lines = Operation::read_lines_from(canvas_path);
        
        CPPUNIT_ASSERT(lines[0] == "P3");
        CPPUNIT_ASSERT(lines[1] == "5 3");
        CPPUNIT_ASSERT(lines[2] == "255");
    }
}
