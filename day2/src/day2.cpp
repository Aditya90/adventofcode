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
#include <string_view>

#include "day2.h"

using namespace std;

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
        // cout << subStrToCheck[--retRed] << endl;
        // Find the first number from the left of this position
        auto numPosition = subStrToCheck.rfind(" ", --retRed);
        size_t digitCount = (retRed - ++numPosition + 1);
        auto stringOfText = std::string(&subStrToCheck[numPosition], digitCount);
        retValue.redCount = stoi(stringOfText);
    }
    auto retBlue = subStrToCheck.find(" blue");
    if (retBlue != std::string::npos)
    {
        // cout << subStrToCheck[--retBlue] << endl;
        // Find the first number from the left of this position
        auto numPosition = subStrToCheck.rfind(" ", --retBlue);
        size_t digitCount = (retBlue - ++numPosition + 1);
        auto stringOfText = std::string(&subStrToCheck[numPosition], digitCount);
        retValue.blueCount = stoi(stringOfText);
    }
    auto retGreen = subStrToCheck.find(" green");
    if (retGreen != std::string::npos)
    {
        // cout << subStrToCheck[--retGreen] << endl;
        // Find the first number from the left of this position
        auto numPosition = subStrToCheck.rfind(" ", --retGreen);
        size_t digitCount = (retGreen - ++numPosition + 1);
        auto stringOfText = std::string(&subStrToCheck[numPosition], digitCount);
        retValue.greenCount = stoi(stringOfText);
    }
    return retValue;
}

/*
void part1(std::string inputFile)
{
    // Get input string for each line of the file
    std::ifstream inFile{inputFile};
    std::string str;

    // Create a map of game number to max number of cubes of each color
    // std::unordered_map<std::size_t, SetOfColorCount> gameNumberToMaxCubes;

    while (std::getline(inFile, str))
    {
        auto pos = str.find("Game ");
    }
    // Track the max number of each color which has been recorded so far, with a map of color to max count

    //
}
*/