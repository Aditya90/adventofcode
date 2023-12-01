add_executable(day1 
               ./src/main.cpp)

add_executable(day1Test
               ./test/day1Test.cpp)

add_library(day1Lib
            ./src/day1.cpp)

target_link_libraries(day1 day1Lib)
target_link_libraries(day1Test day1Lib gtest_main)

include_directories(inc)
include(GoogleTest)
gtest_discover_tests(day1Test)