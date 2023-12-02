#include "gtest/gtest.h"

#include "day2.h"

std::vector<std::string> testStrings = {
    {"Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green"},
    {"Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue"},
    {"Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red"},
    {"Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red"},
    {"Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green"},
};
TEST(findNumRGB, SingleDigit)
{
    ColorStruct expectedOutputBlue{.redCount = 0, .blueCount = 2, .greenCount = 0};
    ASSERT_EQ(expectedOutputBlue, findNumBlueGreenRed(" 2 blue"));
    ColorStruct expectedOutputRed{.redCount = 3, .blueCount = 0, .greenCount = 0};
    ASSERT_EQ(expectedOutputRed, findNumBlueGreenRed(" 3 red"));
    ColorStruct expectedOutputGreen{.redCount = 0, .blueCount = 0, .greenCount = 6};
    ASSERT_EQ(expectedOutputGreen, findNumBlueGreenRed(" 6 green"));
}

TEST(findNumRGB, DoubleDigit)
{
    ColorStruct expectedOutputBlue{.redCount = 0, .blueCount = 22, .greenCount = 0};
    ASSERT_EQ(expectedOutputBlue, findNumBlueGreenRed(" 22 blue"));
    ColorStruct expectedOutputRed{.redCount = 23, .blueCount = 0, .greenCount = 0};
    ASSERT_EQ(expectedOutputRed, findNumBlueGreenRed(" 23 red"));
    ColorStruct expectedOutputGreen{.redCount = 0, .blueCount = 0, .greenCount = 46};
    ASSERT_EQ(expectedOutputGreen, findNumBlueGreenRed(" 46 green"));
}

TEST(findNumRGB, TripleDigit)
{
    ColorStruct expectedOutputBlue{.redCount = 0, .blueCount = 231, .greenCount = 0};
    ASSERT_EQ(expectedOutputBlue, findNumBlueGreenRed(" 231 blue"));
    ColorStruct expectedOutputRed{.redCount = 378, .blueCount = 0, .greenCount = 0};
    ASSERT_EQ(expectedOutputRed, findNumBlueGreenRed(" 378 red"));
    ColorStruct expectedOutputGreen{.redCount = 0, .blueCount = 0, .greenCount = 126};
    ASSERT_EQ(expectedOutputGreen, findNumBlueGreenRed(" 126 green"));
}

TEST(findNumRGB, RgbMixed)
{
    ColorStruct expectedOutput{.redCount = 20, .blueCount = 6, .greenCount = 59};
    ASSERT_EQ(expectedOutput, findNumBlueGreenRed(" 59 green, 6 blue, 20 red"));
}