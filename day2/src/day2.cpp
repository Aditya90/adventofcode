/**
 * @file day2.cpp
 * @author aditya.sreekumar@gmail.com
 * @brief Day 2 solution for AoC 2023
 */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <cassert>

#include "day2.h"

using namespace std;

struct ColorStruct
{
    size_t redCount;
    size_t blueCount;
    size_t greenCount;
}

using SetOfColorCount = std::unordered_set<ColorStruct>;

/**
 * @brief Find the number of blue, green and red cubes in a substring
 *
 * @return SetOfColorCount
 */
ColorStruct
findNumBlueGreenRed(const std::string &subStrToCheck)
{
    ColorStruct retValue;
    auto retRed = subStrToCheck.find(" red");
    if (retRed != std::string::npos)
    {
        retValue.redCount = subStrToCheck[--retRed];
    }
    auto retBlue = subStrToCheck.find(" blue");
    if (retBlue != std::string::npos)
    {
        retValue.blueCount = subStrToCheck[--retBlue];
    }
    auto retGreen = subStrToCheck.find(" green");
    if (retGreen != std::string::npos)
    {
        retValue.greenCount = subStrToCheck[--retGreen];
    }
    return retValue;
}

void part1(std::string inputFile)
{
    // Get input string for each line of the file
    std::ifstream inFile{inputFile};
    std::string str;

    // Create a map of game number to max number of cubes of each color
    std::unordered_map<std::size_t, SetOfColorCount> gameNumberToMaxCubes;

    while (std::getline(inFile, str))
    {
        auto pos = str.find("Game ");
    }
    // Track the max number of each color which has been recorded so far, with a map of color to max count

    //
}