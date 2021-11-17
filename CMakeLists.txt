cmake_minimum_required(VERSION 3.16.5)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled TypeImageClassTester.cpp MyHisto.cpp MyTypeImage.cpp MyIntImage.cpp MyCharImage.cpp MyFloatImage.cpp MyTypeImage.cpp MyFilter.cpp)