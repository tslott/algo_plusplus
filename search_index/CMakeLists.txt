########################################
# CMAKE SETUP
########################################

cmake_minimum_required(VERSION 3.17.0)
project(search_index)

########################################
# C++ VERSIONING
########################################

message(STATUS "Compiling with C++17")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

########################################
# INCLUDES
########################################

include_directories(include)

########################################
# EXECUTABLE
########################################

FILE(GLOB SOURCES ./src/*.cpp)
ADD_EXECUTABLE(run_me.out main.cpp ${SOURCES})

########################################
# TESTING
########################################

enable_testing()
add_subdirectory(tests)
