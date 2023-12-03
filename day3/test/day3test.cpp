#include "gtest/gtest.h"

#include "day3.h"

TEST(findNumberString, ExampleOne)
{
    std::vector<std::vector<char>> testInput =
        {
            {'4', '6', '7', '.', '.', '1', '1', '4', '.', '.'},
            {'.', '.', '.', '*', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '3', '5', '.', '.', '6', '3', '3', '.'}};
    /*
    ......#...
    617*......
    .....+.58.
    ..592.....
    ......755.
    ...$.*....
    .664.598.. }
        };

     */
    std::string expectedOutputFirst{"467"};
    std::pair<size_t, int> expectedOutputLast = {15, 2};

    ASSERT_EQ(expectedOutputFirst, findDigitsToLeft(testInput, 0, 3, true));
    // assert(expectedOutputLast == findNumberString(stringToTest, false));
}
