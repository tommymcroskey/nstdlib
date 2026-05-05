# Garden

## Purpose

Hello, and welcome to the Garden! The goal of this repository is to create a standalone library of containers and algorithms, and to find the bugs common (or not so common) to C++ programming. Each container and algorithm will eventually have its own lock-free and blocking implementations, and each should be profiled against one another. I also will write a short piece about what I learned from each once this process is complete. I hope you enjoy poking around!

## How To Build

### Requires

- C++20 or later
- Ninja

`cmake -B build -G Ninja`

`cmake --build build`

#### To run tests

`ctest --test-dir build --output-on-failure`

*can use default generator but Ninja used above to match mine*

## Implemented

### Data Structures

#### Vector
- [X] Base
- [ ] Lock-Free
- [ ] Blocking
- [ ] Profiling

#### Stack
- [X] Base
- [ ] Lock-Free
- [ ] Blocking
- [ ] Profiling

#### CircularBuffer (Queue)
- [X] Base
- [ ] Lock-Free
- [ ] Blocking
- [ ] Profiling

### Algorithms

#### MergeSort
- [X] Base
- [ ] Lock-Free
- [ ] Blocking
- [ ] Profiling

#### Find
- [ ] Base
- [ ] Lock-Free
- [ ] Blocking
- [ ] Profiling
