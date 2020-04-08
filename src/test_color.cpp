#include "test_color.h"
#include "color.h"
#include "equal.h"

namespace Testing {


    void TestColor::setUp() {
    }

    void TestColor::tearDown() {
    }

    void TestColor::testColorIsTuple() {

        Engine::Color color(-0.5f , 0.4f , 1.7f);
        CPPUNIT_ASSERT(Operation::equal(color.r , -0.5f));
        CPPUNIT_ASSERT(Operation::equal(color.g , 0.4f));
        CPPUNIT_ASSERT(Operation::equal(color.b , 1.7f));
    }

};
