/**
 * @file day1.cpp
 * @author aditya.sreekumar@gmail.com
 * @brief Day 1 solution for AoC 2023
 */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <cassert>
#include <sstream>

#include "day3.h"

using namespace std;

void create2DVectorFromFile(ifstream &infile, std::vector<std::vector<char>> &schematicMap)
{

    std::string str;

    // Iterate through each line in the file
    while (std::getline(infile, str))
    {
        std::vector<char> rowEntries;
        // Save all entries in the file as a vector of chars
        for (char c : str)
        {
            if (c != '\r')
            {
                rowEntries.push_back(c);
            }
        }

        schematicMap.push_back(rowEntries);
    }
}

std::string findDigitsToLeft(const std::vector<std::vector<char>> &schematicMap, size_t rowNum, size_t colNum, bool left)
{
    std::string retVal;
    if (left && colNum > 0)
    {
        int leftIndex{colNum - 1};
        std::stringstream leftString;
        for (; leftIndex >= 0; leftIndex--)
        {

            char val = schematicMap.at(rowNum).at(leftIndex);
            if (!isdigit(schematicMap.at(rowNum).at(leftIndex)))
            {
                break;
            }
            leftString << val;
        }
        retVal = leftString.str();
        reverse(retVal.begin(), retVal.end());
    }
    else if (!left && colNum < schematicMap[0].size() - 2)
    {
        int rightIndex{colNum + 1};
        std::stringstream rightString;
        for (; rightIndex < schematicMap[0].size(); rightIndex++)
        {
            char val = schematicMap.at(rowNum).at(rightIndex);

            if (!isdigit(schematicMap.at(rowNum).at(rightIndex)))
            {
                break;
            }
            rightString << val;
        }

        retVal = rightString.str();
    }

    return retVal;
}

int getPartNumb(const std::vector<std::vector<char>> &schematicMap, size_t rowNum, size_t colNum)
{
    size_t schematicMapRowNum = schematicMap.size();
    size_t schematicMapColNum = schematicMap[0].size();
    std::string num;
    std::string digitsToLeft, digitsToRight;
    char charAtPsn = schematicMap.at(rowNum).at(colNum);
    if (isdigit(charAtPsn))
    {
        digitsToLeft = findDigitsToLeft(schematicMap, rowNum, colNum, true);
        digitsToRight = findDigitsToLeft(schematicMap, rowNum, colNum, false);
        num.append(digitsToLeft);
        num.push_back(charAtPsn);
        num.append(digitsToRight);
    }
    else
    {
        num = "0";
    }

    return stoi(num);
}
int sumAndListAdjacentNums(const std::vector<std::vector<char>> &schematicMap,
                           size_t rowNum, size_t colNum, std::unordered_set<int> &partNumbers)
{
    size_t schematicMapRowNum = schematicMap.size();
    size_t schematicMapColNum = schematicMap[0].size();

    std::unordered_set<int> partNumbersTemp;
    int cumSum{0};

    for (int i = rowNum - 1; i <= rowNum + 1; i++)
    {
        for (int j = colNum - 1; j <= colNum + 1; j++)
        {
            if ((i != j) && (i >= 0) && (j >= 0) && (i <= schematicMapRowNum - 1) && (j <= schematicMapColNum - 1))
            {
                int partNum = getPartNumb(schematicMap, i, j);
                if ((partNum != 0) && (partNumbersTemp.find(partNum) == partNumbersTemp.end()))
                {
                    partNumbersTemp.insert(partNum);
                    cumSum += partNum;
                }
            }
        }
    }

    partNumbers.insert(partNumbersTemp.begin(), partNumbersTemp.end());

    return cumSum;
}
void part1(std::string inputFile)
{
    ifstream inFile{inputFile};
    std::vector<std::vector<char>> schematicMap;
    create2DVectorFromFile(inFile, schematicMap);
    std::cout << "NumRows: " << schematicMap.size() << ", NumCols: " << schematicMap[0].size() << endl;

    // For each entry in the matrix of inputs, check the cells around each symbol
    // to see if a number exists. Add those numbers to a set of part numbers
    size_t schematicMapRowNum = schematicMap.size();
    size_t schematicMapColNum = schematicMap[0].size();
    std::unordered_set<int> partNumbers;
    int accumulatedPartNumber{0};
    for (size_t rowNum = 0; rowNum < schematicMapRowNum; rowNum++)
    {
        for (size_t colNum = 0; colNum < schematicMapColNum; colNum++)
        {
            char charAtIndex = schematicMap[rowNum][colNum];
            if (!isalnum(charAtIndex) && !isspace(charAtIndex) && !iscntrl(charAtIndex) && charAtIndex != '.')
            {
                cout << charAtIndex << endl;
                accumulatedPartNumber += sumAndListAdjacentNums(schematicMap, rowNum, colNum, partNumbers);
            }
        }
    }
    std::cout << "Sum of all values: " << accumulatedPartNumber << endl;
}