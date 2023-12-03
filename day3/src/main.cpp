#include <iostream>
#include "day1.h"

// Pass in file name as input argument
int main(int argc, char **argv)
{
    if (argc == 2)
    {
        part1(argv[1]);
        part2(argv[1]);
    }
    else
    {
        throw("Pass in file name as input argument!");
    }

    return 0;
}