add_executable(day2 
               ./src/main.cpp)

add_executable(day2Test
               ./test/day2Test.cpp)

add_library(day2Lib
            ./src/day2.cpp)

target_link_libraries(day2 day2Lib)
target_link_libraries(day2Test day2Lib gtest_main)

include_directories(inc)
include(GoogleTest)
gtest_discover_tests(day2Test)