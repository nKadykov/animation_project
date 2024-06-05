cmake_minimum_required(VERSION 3.10)
project(animation_project)

set(CMAKE_CXX_STANDART 23)
set(CMAKE_CXX_STANDART_REQUIRED True)

set(CMAKE_TOOLCHANE_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")

include_directories(include)

set(ASSETS_FOLDER ${CMAKE_SOURCE_DIR}/assets)
set(ASSETS_OUTPUT_DIR Release/assets)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
add_executable(animation_project include/gold.h src/main.cpp src/gold.cpp)
target_link_libraries(animation_project sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

add_custom_command(
    TARGET animation_project POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${ASSETS_FOLDER} ${ASSETS_OUTPUT_DIR}
    COMMENT "Copying assets to output directory"
)
set_target_properties(animation_project PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if (WIN32)
    set_target_properties(animation_project PROPERTIES WIN32_EXECUTABLE YES LINK_FLAGS "/ENTRY:mainCRTStartup")
endif()