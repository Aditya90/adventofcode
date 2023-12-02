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
    cout << "posStart: " << posStart << ", posEnd: " << posEnd << endl;

    do
    {
        cout << count++ << endl;

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
    cout << "Start Maps" << endl;

    std::vector<ColorStruct> gameNumberToMaxCubes;
    gameNumberToMaxCubes.reserve(100);
    size_t gameNum(0);

    while (std::getline(inFile, str))
    {
        // Track the max number of each color which has been recorded so far, with a map of color to max count
        gameNumberToMaxCubes.emplace_back();
        getMaxGame(str, gameNumberToMaxCubes[gameNum++]);
        cout << gameNumberToMaxCubes[gameNum - 1];
    }

    // Determine which games would have been possible if the bag had been loaded with only 12 red cubes,
    // 13 green cubes, and 14 blue cubes. What is the sum of the IDs of those games?
    cout << "Start Check" << endl;
    ColorStruct colorCheck = {.redCount = 12, .blueCount = 14, .greenCount = 13};
    std::size_t gameCountSum{0};
    std::size_t gameCount{0};
    for (auto &maxColor : gameNumberToMaxCubes)
    {
        gameCount++;

        if ((colorCheck.blueCount >= maxColor.blueCount) &&
            (colorCheck.redCount >= maxColor.redCount) &&
            (colorCheck.greenCount >= maxColor.greenCount))
        {
            cout << gameCount << endl;
            gameCountSum += gameCount;
        }
    }

    cout << "Game Count: " << gameCountSum << endl;
}

void part2(std::string inputFile)
{
    // Get input string for each line of the file
    std::ifstream inFile{inputFile};
    std::string str;

    // Create a map of game number to max number of cubes of each color
    cout << "Start Maps" << endl;

    std::vector<ColorStruct> gameNumberToMaxCubes;
    gameNumberToMaxCubes.reserve(100);
    size_t gameNum(0);

    while (std::getline(inFile, str))
    {
        // Track the max number of each color which has been recorded so far, with a map of color to max count
        gameNumberToMaxCubes.emplace_back();
        getMaxGame(str, gameNumberToMaxCubes[gameNum++]);
        cout << gameNumberToMaxCubes[gameNum - 1];
    }

    // Add the sum of game powers
    cout << "Start Check" << endl;
    std::size_t gamePowerSum{0};
    for (auto &maxColor : gameNumberToMaxCubes)
    {
        // Calculate game power
        size_t gamePower = maxColor.blueCount * maxColor.redCount * maxColor.greenCount;

        gamePowerSum += gamePower;
    }

    cout << "Game Power Sum: " << gamePowerSum << endl;
}