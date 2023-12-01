/**
 * @file day1.cpp
 * @author aditya.sreekumar@gmail.com
 * @brief Day 1 solution for AoC 2023

The newly-improved calibration document consists of lines of text; each line originally contained a specific calibration value that the Elves now need to recover. On each line, the calibration value can be found by combining the first digit and the last digit (in that order) to form a single two-digit number.

For example:

1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet
In this example, the calibration values of these four lines are 12, 38, 15, and 77. Adding these together produces 142.

Consider your entire calibration document. What is the sum of all of the calibration values?
 */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    ifstream inFile{"day1input.txt"};
    std::string str;
    unsigned long sumOfCalibrationValues{0};

    // Iterate through each line in the file
    while (std::getline(inFile, str))
    {
        auto isANumber = [](char c)
        {
            if (c >= '0' and c <= '9')
            {
                return true;
            }
            return false;
        };
        // Find the first digit in the string
        auto firstValue = std::find_if(str.begin(), str.end(), isANumber);

        // Find the last digit in the string
        auto lastValue = std::find_if(str.rbegin(), str.rend(), isANumber);

        // Concatante the 2 digits together to form a two digit number
        std::string concatString = std::string(1, *firstValue) + *lastValue;

        // Convert the 2 digit string into a number and add it to the tracked total
        cout << "Input string: " << str << endl;
        cout << "Concat string : " << concatString << endl;

        sumOfCalibrationValues += stoi(concatString);
    }

    cout << "Sum of all values: " << sumOfCalibrationValues << endl;

    return 0;
}