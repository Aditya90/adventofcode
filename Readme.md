# Readme

Solutions and work for the Advent of Code 2023 - https://adventofcode.com/

Languages/tools
1. C++
2. Python
3. CMake
4. GoogleTest

# Notes

## 12/4/2023
- After day 2 I quickly realized that C++ became too cumbersome for list manipulation and string parsing, so I moved to Python. We'll see how it goes

# Building the solution for any day

For building the solution for dayx:

```
mkdir build && cd build
make -j8 dayx
./bin/dayx ../dayx/src/day1input.txt
```

Unit test targets are available separately