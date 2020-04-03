cmake_minimum_required(VERSION 2.6)

include_directories(include)

set(Source
    src/main.cpp
    src/unit_test.cpp
    src/test_tuple.cpp
    src/tuple.cpp
    src/equal.cpp
    src/vector.cpp
    src/app.cpp
    src/shape.cpp
    )
add_executable(test_pro ${Source})
target_link_libraries(test_pro ${GTEST_LIBRARIES} cppunit sfml-graphics sfml-window sfml-system pthread)
