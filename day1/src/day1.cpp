/**
 * @file day1.cpp
 * @author aditya.sreekumar@gmail.com
 * @brief Day 1 solution for AoC 2023
 */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <cassert>

#include "day1.h"

using namespace std;

void part1(std::string inputFile)
{
    ifstream inFile{inputFile};
    std::string str;
    unsigned long sumOfCalibrationValues{0};

    // Iterate through each line in the file
    while (std::getline(inFile, str))
    {
        // Find the first digit in the string
        auto firstValueDigit = str.find_first_of("0123456789");

        // Find the last digit in the string
        auto lastValueDigit = str.find_last_of("0123456789");

        // Concatante the 2 digits together to form a two digit number
        std::string concatString = std::string(1, str.at(firstValueDigit)) + str.at(lastValueDigit);

        // Convert the 2 digit string into a number and add it to the tracked total

        sumOfCalibrationValues += stoi(concatString);
    }

    std::cout << "Sum of all values: " << sumOfCalibrationValues << endl;
}

std::pair<size_t, int> findNumberString(const string &str, bool first = true)
{
    size_t retStringPos;
    int retStringNum{0};

    if (first)
    {
        retStringPos = std::string::npos;
    }
    else
    {
        retStringPos = 0;
    }

    std::unordered_map<std::string, int> textForNumbers = {
        {"zero", 0},
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9}};
    for (auto numberString : textForNumbers)
    {
        size_t retVal = str.find(numberString.first);

        if (first)
        {
            retVal = str.find(numberString.first);
            if (retVal < retStringPos)
            {
                retStringPos = retVal;
                retStringNum = numberString.second;
            }
        }
        else
        {
            retVal = str.rfind(numberString.first);
            if ((retVal != std::string::npos) && (retVal >= retStringPos))
            {
                retStringPos = retVal;
                retStringNum = numberString.second;
            }
        }
    }

    return std::pair<size_t, int>{retStringPos, retStringNum};
};

void part2(std::string inputFile)
{
    ifstream inFile{inputFile};
    std::string str;
    unsigned long sumOfCalibrationValues{0};

    std::string firstValue, lastValue;
    // Iterate through each line in the file
    std::cout << "Input file: " << inputFile << endl;
    while (std::getline(inFile, str))
    {
        // Find the first digit in the string
        auto firstValueDigit = str.find_first_of("0123456789");

        // Find the first substr number
        auto firstValueSubstrPair = findNumberString(str);

        // Take whichever was first among the 2 above
        if (firstValueDigit > firstValueSubstrPair.first)
        {
            firstValue = std::to_string(firstValueSubstrPair.second);
        }
        else
        {
            firstValue = str.at(firstValueDigit);
        }

        // Find the last digit in the string
        auto lastValueDigit = str.find_last_of("0123456789");

        // Find the last substr number
        auto lastValueSubstrPair = findNumberString(str, false);

        // Take whichever was last among the 2 above
        if ((lastValueSubstrPair.first != std::string::npos) && (lastValueDigit < lastValueSubstrPair.first))
        {
            lastValue = std::to_string(lastValueSubstrPair.second);
        }
        else
        {
            lastValue = str.at(lastValueDigit);
        }
        // Concatante the 2 digits together to form a two digit number
        std::string concatString = firstValue + lastValue;

        // Convert the 2 digit string into a number and add it to the tracked total

        sumOfCalibrationValues += stoi(concatString);
    }

    std::cout << "Sum of all values: " << sumOfCalibrationValues << endl;
}