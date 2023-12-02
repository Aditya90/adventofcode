add_executable(dayx 
               ./src/main.cpp)

add_executable(dayxTest
               ./test/dayxTest.cpp)

add_library(dayxLib
            ./src/dayx.cpp)

target_link_libraries(dayx dayxLib)
target_link_libraries(dayxTest dayxLib gtest_main)

include_directories(inc)
include(GoogleTest)
gtest_discover_tests(dayxTest)