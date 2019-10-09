project(Longmath)

add_library(longmath_lib STATIC longmath.cpp longmath.h)

add_executable(longmath main.cpp)
target_link_libraries(longmath PRIVATE longmath_lib)