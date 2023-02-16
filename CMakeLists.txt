cmake_minimum_required(VERSION 3.23)
project(Slatformer)

set(CMAKE_CXX_STANDARD 14)

include_directories(C:/Users/Wake/API/SDL2/include)
link_directories(C:/Users/Wake/API/SDL2/lib)

add_executable(Slatformer main.cpp renderwindow.cpp RenderWindow.h)

add_custom_target(copy_resources ALL
COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/resources
        ${PROJECT_BINARY_DIR}/resources
COMMENT "Copying resources into binary directory")

add_dependencies(Slatformer copy_resources)

target_link_libraries(Slatformer -lmingw32 -lSDL2main -lSDL2 -lSDL2_image)

