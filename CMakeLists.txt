cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_C_COMPILER gcc)

project(AdventOfCode)

# add_compile_options(-std=c++20)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# add_compile_options(/std:c++latest)

# Specify directory for bins and libs
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Disable the gtests for google benchmark as we dont have a gtest dependency added yet
set(BENCHMARK_ENABLE_GTEST_TESTS OFF)
set(BENCHMARK_FORMAT json)

# Add source sub directory
add_subdirectory(day1)
add_subdirectory(day2)