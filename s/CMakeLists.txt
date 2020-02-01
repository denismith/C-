cmake_minimum_required(VERSION 3.10)

# set the project name
project(snake)

find_package(SFML 2 COMPONENTS graphics window REQUIRED)
add_executable(snake snake.cpp)
target_link_libraries(snake sfml-graphics sfml-window)

