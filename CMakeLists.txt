cmake_minimum_required(VERSION 3.5)

project(vsp-utils)

set (CMAKE_CXX_FLAGS "-m32")
set (CMAKE_CXX_STANDARD 20)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(vsp-utils SHARED src/interface.cpp src/symbol.cpp)
target_include_directories(vsp-utils PUBLIC ${PROJECT_SOURCE_DIR}/include)

