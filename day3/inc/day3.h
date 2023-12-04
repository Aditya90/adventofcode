#pragma once
#include <utility>
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <unordered_set>
/*
You turn around to see a slightly-greasy Elf with a wrench and a look of surprise. "Sorry, I wasn't expecting anyone! The gondola lift isn't working right now; it'll still be a while before I can fix it." You offer to help.

The engineer explains that an engine part seems to be missing from the engine, but nobody can figure out which one. If you can add up all the part numbers in the engine schematic, it should be easy to work out which part is missing.

The engine schematic (your puzzle input) consists of a visual representation of the engine. There are lots of numbers and symbols you don't really understand, but apparently any number adjacent to a symbol, even diagonally, is a "part number" and should be included in your sum. (Periods (.) do not count as a symbol.)

Here is an example engine schematic:

467..114..
...*......
..35..633.
......#...
617*......
.....+.58.
..592.....
......755.
...$.*....
.664.598..
In this schematic, two numbers are not part numbers because they are not adjacent to a symbol: 114 (top right) and 58 (middle right). Every other number is adjacent to a symbol and so is a part number; their sum is 4361.

Of course, the actual engine schematic is much larger. What is the sum of all of the part numbers in the engine schematic?


 *
*/
void part1(std::string inputFile);

void part2(std::string inputFile);

void create2DVectorFromFile(const std::ifstream &infile, std::vector<std::vector<char>> &schematicMap);
std::string findDigitsToLeft(const std::vector<std::vector<char>> &schematicMap, size_t rowNum, size_t colNum, bool left = true);
int getPartNumb(const std::vector<std::vector<char>> &schematicMap, size_t rowNum, size_t colNum);

int sumAndListAdjacentNums(const std::vector<std::vector<char>> &schematicMap,
                              size_t rowNum, size_t colNum, std::unordered_set<size_t> &partNumbers);
