cmake_minimum_required(VERSION 3.22)
project(relearn CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra -Wpedantic)

include(FetchContent)
FetchContent_Declare(googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip)
FetchContent_MakeAvailable(googletest)
enable_testing()

add_library(core src/lowpass.cpp)
target_include_directories(core PUBLIC include)

add_executable(core_tests test/lowpass_test.cpp)
target_link_libraries(core_tests core GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(core_tests)