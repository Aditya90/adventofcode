add_executable(day3
               ./src/main.cpp)

add_executable(day3Test
               ./test/day3Test.cpp)

add_library(day3Lib
            ./src/day3.cpp)

target_link_libraries(day3 day3Lib)
target_link_libraries(day3Test day3Lib gtest_main)

include_directories(inc)
include(GoogleTest)
gtest_discover_tests(day3Test)