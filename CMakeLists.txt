cmake_minimum_required(VERSION 3.17)
project(RPG_Game)

set(CMAKE_CXX_STANDARD 14)

add_executable(RPG_Game main.cpp utility.cpp utility.h items.cpp items.h beings.cpp beings.h spells.cpp spells.h)