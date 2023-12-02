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
#include <sstream>
#include <vector>

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

void getMaxGame(std::string &gameString, ColorStruct &gameNumberToMaxCubes)
{
    // std::istringstream inputString{str};
    // std::string currentWord;
    // std::string prevWord;
    // std::size_t gameNum;
    // while (inputString >> currentWord)
    //{
    //    if (currentWord == ":")
    //    {
    //        gameNum = stoi(prevWord);
    //    }
    // }

    auto posStart = gameString.find(":");
    auto posEnd = gameString.find(";");
    std::string subString;
    size_t count{0};

    cout << "gameString: " << gameString << endl;

    do
    {
        cout << count++ << endl;
        cout << "posStart: " << posStart << ", posEnd: " << posEnd << endl;

        subString = std::string(gameString, posStart, posEnd - posStart);
        cout << "Rest of String: " << subString << endl;
        auto gameCount = findNumBlueGreenRed(subString);

        if (gameNumberToMaxCubes.blueCount < gameCount.blueCount)
        {
            gameNumberToMaxCubes.blueCount = gameCount.blueCount;
        }
        if (gameNumberToMaxCubes.redCount < gameCount.redCount)
        {
            gameNumberToMaxCubes.redCount = gameCount.redCount;
        }
        if (gameNumberToMaxCubes.greenCount < gameCount.greenCount)
        {
            gameNumberToMaxCubes.greenCount = gameCount.greenCount;
        }
        posStart = posEnd + 1;
        posEnd = gameString.find(";", posStart);
        if (posEnd == std::string::npos)
        {
            posEnd = gameString.length();
        }
        cout << "posStart: " << posStart << ", posEnd: " << posEnd << endl;

    } while (posEnd > posStart);
}

void part1(std::string inputFile)
{
    // Get input string for each line of the file
    std::ifstream inFile{inputFile};
    std::string str;

    // Create a map of game number to max number of cubes of each color
    std::vector<ColorStruct> gameNumberToMaxCubes;
    size_t gameNum(1);

    while (std::getline(inFile, str))
    {
        gameNumberToMaxCubes.emplace_back(ColorStruct{});
        getMaxGame(str, gameNumberToMaxCubes[gameNum++]);
    }
    // Track the max number of each color which has been recorded so far, with a map of color to max count

    //
}
