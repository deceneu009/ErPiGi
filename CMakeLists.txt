cmake_minimum_required(VERSION 3.28)
project(ErPiGi)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(character)
include_directories(character/enemy)
include_directories(character/hero)
include_directories(game/inventory)
include_directories(utils)

add_executable(ErPiGi
        character/enemy/Enemy.cpp
        character/enemy/Enemy.h
        character/hero/Hero.cpp
        character/hero/Hero.h
        character/generator.cpp
        character/generator.h
        utils/utils.cpp
        utils/utils.h
        Game.cpp
        game/levels/Levels.cpp
        game/levels/Levels.h
        character/player/Player.cpp
        character/player/Player.h
        game/gameplay/Game.cpp
        game/gameplay/Game.h
        game/gameplay/Game.h
        game/gameplay/Game.h
)
