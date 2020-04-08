#include "test_color.h"
#include "color.h"
#include "equal.h"
#include "convert.h"

namespace Testing {


    void TestColor::setUp() {
    }

    void TestColor::tearDown() {
    }

    void TestColor::testColorIsTuple() {

        Engine::Color color(-0.5f , 0.4f , 1.7f);
        CPPUNIT_ASSERT(Operation::equal(color.red() , -0.5f));
        CPPUNIT_ASSERT(Operation::equal(color.green() , 0.4f));
        CPPUNIT_ASSERT(Operation::equal(color.blue() , 1.7f));
    }

    
    void TestColor::testAddColor() {

        Engine::Color color1(0.9f , 0.6f , 0.75f);
        Engine::Color color2(0.7f , 0.1f , 0.25f);
        TwoD::Tuple tuple_result = color1 + color2;
        Engine::Color result =  Operation::tupleToColor(tuple_result);

        CPPUNIT_ASSERT(result == Engine::Color(1.6f , 0.7f, 1.0f));
    }

    void TestColor::testSubColor() {

        Engine::Color color1(0.9f , 0.6f , 0.75f);
        Engine::Color color2(0.7f , 0.1f , 0.25f);
        TwoD::Tuple tuple_result = color1 - color2;
        Engine::Color result =  Operation::tupleToColor(tuple_result);

        CPPUNIT_ASSERT(result == Engine::Color(0.2f , 0.5f, 0.5f));
    }

};
