cmake_minimum_required(VERSION 3.13.3)
project(hangman)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_subdirectory(src)

add_subdirectory(app)

enable_testing()
add_subdirectory(googletest)

add_subdirectory(tests)