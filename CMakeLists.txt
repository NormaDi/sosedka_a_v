cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 20)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")

project(sosedka_a_v)

include(cmake/build_prefix.cmake)
include_directories(prj.labs)

add_subdirectory(prj.labs)
add_subdirectory(prj.test)