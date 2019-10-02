cmake_minimum_required (VERSION 2.8)

project(game)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

add_definitions('-Wall')

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

set(SOURCES
    src/main.cpp
    src/game.cpp
    src/texturemanager.cpp
    src/gameobject.cpp
    src/map.cpp
    include/game.hpp
    include/texturemanager.hpp
    include/gameobject.hpp
    include/map.hpp
    include/ecs.hpp
    include/components.hpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
target_include_directories(${PROJECT_NAME}
    PRIVATE src/ include/
)
