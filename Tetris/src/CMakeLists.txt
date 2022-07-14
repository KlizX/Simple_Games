# CMakeList.txt : CMake project for Snake, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.

SET(SOURCES
	Point.cpp Point.h
	InputManager.h
	InputManagerWin.cpp InputManagerWin.h
	Engine.cpp Engine.h
	PlayTetris.cpp PlayTetris.h
	GameTxt.cpp GameTxt.h
	Tetris.cpp
)

add_executable(Tetris ${SOURCES})

# TODO: Add tests and install targets if needed.
