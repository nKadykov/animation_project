cmake_minimum_required(VERSION 3.10)
project(animation_project)

set(CMAKE_TOOLCHANE_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")

include_directories(include)

add_executable(animation_project src/main.cpp)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
target_link_libraries(animation_project sfml-system sfml-window sfml-graphics sfml-network sfml-audio)