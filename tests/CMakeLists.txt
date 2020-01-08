cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include("tools/gate/cmake/HunterGate.cmake")

HunterGate(
        URL "https://github.com/ruslo/hunter/archive/v0.23.31.tar.gz"
        SHA1 "3d94b8522541c4c8eaac606f4c47d09322a8019c"
)

project(tests_LZW)

string(APPEND CMAKE_CXX_FLAGS "-Wall -Wextra -Wno-unused-command-line-argument -Wnon-virtual-dtor -pedantic")

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

add_executable(lzw_tests
        tests/tests.cpp
        ../sources/LZW.cpp
        ../sources/BinaryFile.cpp)
target_include_directories(lzw_tests PUBLIC project/include)
target_link_libraries(lzw_tests
        GTest::main)

enable_testing()
add_test(NAME tests COMMAND lzw_tests)
