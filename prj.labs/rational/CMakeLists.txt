project(Rational)

add_library(rational_lib STATIC rational.cpp rational.h)

add_executable(rational main.cpp)
target_link_libraries(rational PRIVATE rational_lib)