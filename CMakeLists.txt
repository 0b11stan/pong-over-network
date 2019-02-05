cmake_minimum_required(VERSION 3.12)
project(pong-over-network)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set(SOURCE_FILES
        src/main.cpp
        src/PlayerOutput.h
        src/PlayerInput.h
        src/SDL2Output.h src/SDL2Output.cpp
        src/SDL2Input.h src/SDL2Input.cpp
        src/Position.h
        src/Ball.h src/Ball.cpp
        src/Game.h src/Game.cpp
        src/Movement.h
        src/Room.cpp src/Room.h
        src/Player.h
        src/HTTP.cpp src/HTTP.h
        src/Server.cpp src/Server.h
        src/HTTPResponse.cpp src/HTTPResponse.h
        src/HUD.cpp src/HUD.h src/LocalPlayer.h src/RemotePlayer.h src/PlayerPicker.cpp src/PlayerPicker.h)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(pon ${SOURCE_FILES})
target_link_libraries(pon ${SDL2_LIBRARY} SDL2_ttf curl)
