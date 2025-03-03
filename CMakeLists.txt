cmake_minimum_required(VERSION 3.28)
project(ErPiGi)

set(CMAKE_CXX_STANDARD 14)

# Detect OS
if(UNIX AND NOT APPLE)
    message(STATUS "Compiling for Linux")
elseif(WIN32)
    message(STATUS "Compiling for Windows")
endif()

# Define executable first
add_executable(ErPiGi
    character/enemy/Enemy.cpp
    character/hero/Hero.cpp
    character/generator.cpp
    utils/utils.cpp
    ErPiGi.cpp
    game/levels/Levels.cpp
    character/player/Player.cpp
    game/gameplay/Game.cpp
)

# Include directories after defining the executable
target_include_directories(ErPiGi PRIVATE 
    character 
    character/enemy 
    character/hero 
    game/inventory 
    utils
)

# Link pthread if needed
#target_link_libraries(ErPiGi pthread)
