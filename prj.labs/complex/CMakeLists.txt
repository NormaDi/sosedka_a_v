project(Complex)

add_library(complex_lib STATIC complex.cpp complex.h)

add_executable(complex main.cpp)
target_link_libraries(complex PRIVATE complex_lib)