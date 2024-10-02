
# Computer Vision Project Overview

This project contains multiple independent branches, each implementing different image processing tasks and solutions. The branches are designed to work separately, and merging them is not recommended due to their differing implementations and purposes.

## Table of Contents
- [Project Structure](#project-structure)
- [Branch Descriptions](#branch-descriptions)
  - [aufgabe1](#aufgabe1)
  - [aufgabe2](#aufgabe2)
  - [aufgabe3](#aufgabe3)
  - [aufgabe4](#aufgabe4)
  - [aufgabe5](#aufgabe5)
- [Main Branch](#main-branch)
- [Conclusion](#conclusion)

## Project Structure

The project consists of the following branches:
- `aufgabe1`
- `aufgabe2`
- `aufgabe3`
- `aufgabe4`
- `aufgabe5`
- `main`

Each branch implements specific functionalities related to image processing and should be considered as individual units.

## Branch Descriptions

### aufgabe1
- **Files**: `MyHisto.cpp`, `MyHisto.h`, `MyImage.cpp`, `MyImage.h`, `ImageClassTester.cpp`, etc.
- **Description**: 
  - Implements basic histogram calculation and image processing functionality.
  - `ImageClassTester.cpp` serves as a testing environment for the `MyHisto` and `MyImage` classes.

### aufgabe2
- **Files**: Same as `aufgabe1`.
- **Description**: 
  - This branch continues from `aufgabe1` but does not add significant new functionality.

### aufgabe3
- **Files**: Includes `QuickSort.cpp` in addition to files from `aufgabe1` and `aufgabe2`.
- **Description**: 
  - Adds a QuickSort implementation that could be used for sorting image data or histogram values.

### aufgabe4
- **Files**: 
  - Additional files include `MyCharImage.cpp`, `MyFilter.cpp`, `MyFloatImage.cpp`, `MyIntImage.cpp`, `MyTypeImage.cpp`.
  - `TypeImageClassTester.cpp` for testing different image types and filters.
  - Documentation file: `ReadMe.txt`
  - Image file: `class.png` (likely illustrates class structure)
- **Description**: 
  - Introduces various image processing classes working on different data types (e.g., `MyFloatImage`, `MyIntImage`).
  - Implements filters and other image manipulation functions.

### aufgabe5
- **Files**: 
  - Additional files: `MyPrimitive.cpp`, `MyPrimitive.h`.
  - Extends the classes from `aufgabe4`.
  - Documentation file: `ReadMe.txt`.
  - Image file: `class.png`.
- **Description**: 
  - Implements basic image operations (primitive operations).
  - Builds on existing classes from `aufgabe4`.

## Main Branch
- **Files**: 
  - Contains basic image processing files (`MyHisto`, `MyImage`) without additional advanced functionality found in other branches.
- **Description**: 
  - Provides the basic framework for the project, serving as a starting point for all tasks.

## Conclusion
- Each branch (`aufgabe1` through `aufgabe5`) is independent and implements specific functionalities.
- Merging branches is not recommended as they cover different aspects and solutions of image processing.
- Refer to the respective README files within each branch for more detailed documentation.
