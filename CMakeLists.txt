cmake_minimum_required(VERSION 2.6)

include_directories(include)

set(Source
    src/main.cpp
    src/unit_test.cpp
    src/test_tuple.cpp
    src/test_canvas.cpp
    src/test_color.cpp
    src/tuple.cpp
    src/vector.cpp
    src/app.cpp
    src/color.cpp
    src/canvas.cpp
    src/operation.cpp
    src/pixle_data.cpp
    src/world.cpp
    src/shape.cpp
    src/fps.cpp
    src/matrix.cpp
    src/test_matrix.cpp
    )
add_executable(test_pro ${Source})
target_link_libraries(test_pro ${GTEST_LIBRARIES} cppunit SDL2 pthread)
