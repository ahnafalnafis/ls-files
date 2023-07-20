cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

project(
  ls-files
  VERSION 0.0.1
  LANGUAGES CXX)

add_compile_options(-Wall -Wextra -g)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
add_executable(ls-files src/main.cpp)
