# Readme

Solutions and work for the Advent of Code 2023 - https://adventofcode.com/

Languages/tools
1. C++
2. CMake
3. GoogleTest

# Building the solution for any day

For building the solution for dayx:

```
mkdir build && cd build
make -j8 dayx
./bin/dayx ../dayx/src/day1input.txt
```

Unit test targets are available separately