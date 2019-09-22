cmake_minimum_required(VERSION 3.6)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")

project(sosedka_a_v)

include(cmake/build_prefix.cmake)

add_subdirectory(prj.labs)