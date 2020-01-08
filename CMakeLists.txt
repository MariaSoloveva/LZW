cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(lzw)

add_executable(lzw main.cpp
                   sources/LZW.cpp
                   sources/BinaryFile.cpp)
