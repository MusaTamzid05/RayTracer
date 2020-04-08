#include "test_canvas.h"
#include "canvas.h"

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
}
