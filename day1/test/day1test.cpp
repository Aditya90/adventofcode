#include "gtest/gtest.h"

#include "day1.h"

TEST(findNumberString, ExampleOne)
{
    std::string stringToTest{"asdasone3qweasdtwo5"};
    std::pair<size_t, int> expectedOutputFirst = {5, 1};
    std::pair<size_t, int> expectedOutputLast = {15, 2};

    assert(expectedOutputFirst == findNumberString(stringToTest, true));
    assert(expectedOutputLast == findNumberString(stringToTest, false));
}

TEST(findNumberString, ExampleTwo)
{
    std::string stringToTest{"one2a6666sd3asd"};
    std::pair<size_t, int> expectedOutputFirst = {0, 1};
    std::pair<size_t, int> expectedOutputLast = {0, 1};

    assert(expectedOutputFirst == findNumberString(stringToTest, true));
    assert(expectedOutputLast == findNumberString(stringToTest, false));
}