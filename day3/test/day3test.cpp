#include "gtest/gtest.h"

#include "day3.h"

TEST(findNumberString, findDigitsWhenIndexValid)
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

    ASSERT_EQ(expectedOutputFirst, findDigitsToLeft(testInput, 0, 3, true));
    // assert(expectedOutputLast == findNumberString(stringToTest, false));
}

TEST(findNumberString, sumAndListAdjacentNums)
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
    int expectedOutputFirst{467 + 35};
    std::unordered_set<int> expectedPartNumbers{467, 35};
    std::unordered_set<int> returnPartNumbers;

    ASSERT_EQ(expectedOutputFirst, sumAndListAdjacentNums(testInput, 1, 3, returnPartNumbers));
    ASSERT_EQ(expectedPartNumbers, returnPartNumbers);
    // assert(expectedOutputLast == findNumberString(stringToTest, false));
}