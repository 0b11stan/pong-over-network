cmake_minimum_required(VERSION 3.12)
project(brockenbrick)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set(SOURCE_FILES
        src/main.cpp
        src/PlayerOutput.h
        src/PlayerInput.h
        src/SDL2Output.h src/SDL2Output.cpp
        src/SDL2Input.h src/SDL2Input.cpp
        src/Position.h src/Position.cpp
        src/Ball.h src/Ball.cpp
        src/Game.h src/Game.cpp
        src/Movement.cpp src/Movement.h
        src/Room.cpp src/Room.h
        src/Pad.cpp src/Pad.h
        src/Remote.cpp src/Remote.h)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(brockenbrick ${SOURCE_FILES})
target_link_libraries(brockenbrick ${SDL2_LIBRARY} curl)
