# CMakeList.txt : CMake project for Snake, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.

SET(SOURCES
	Engine.cpp Engine.h
	GameInLife.cpp GameInLife.h
	GameTxt.cpp GameTxt.h
	GameOfLife.cpp
)

add_executable(GameOfLife ${SOURCES})

# TODO: Add tests and install targets if needed.
