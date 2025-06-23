# C++ Modules Workspace

This repository contains a collection of C++ exercises, organized by modules and subprojects. It is designed to help you practice and master various C++ programming concepts, from basic syntax to advanced object-oriented programming and STL usage.

## Table of Contents
- [Overview](#overview)
- [Directory Structure](#directory-structure)
- [Prerequisites](#prerequisites)
- [Building and Running](#building-and-running)
- [Contributing](#contributing)
- [License](#license)

## Overview
This workspace is structured into several modules (CPP00, CPP01, ...), each containing multiple exercises. Each exercise is self-contained, with its own source files and Makefile for easy compilation and testing.

## Directory Structure
```
CPP/
  ├── CPP00/
  ├── CPP01/
  ├── CPP02/
  ├── CPP03/
  ├── CPP04/
  ├── CPP05/
  ├── CPP06/
  ├── CPP07/
  ├── CPP08/
  └── CPP09/
```
- Each `CPPXX` folder represents a module.
- Each module contains several exercises (`ex00`, `ex01`, ...), each with its own `Makefile` and source files.
- Some modules may include additional files or logs for testing and demonstration purposes.

## Prerequisites
- A C++ compiler (e.g., `g++`, `clang++`) supporting C++98 or later.
- `make` utility for building the projects.
- Unix-like environment (Linux, macOS, or WSL on Windows recommended).

## Building and Running
To build and run a specific exercise:

1. Navigate to the exercise directory. For example:
   ```sh
   cd CPP/CPP01/ex00
   ```
2. Build the project using `make`:
   ```sh
   make
   ```
3. Run the resulting executable (the name may vary, often `./main` or as specified in the Makefile):
   ```sh
   ./main
   ```
4. To clean up build files:
   ```sh
   make clean
   ```

Repeat these steps for any other exercise or module.

## Contributing
Contributions are welcome! Please open an issue or submit a pull request for any improvements, bug fixes, or new exercises.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details. 