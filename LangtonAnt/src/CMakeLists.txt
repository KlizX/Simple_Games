# CMakeList.txt : CMake project for Snake, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.

SET(SOURCES
	Engine.cpp Engine.h
	Play.cpp Play.h
	CmdGUI.cpp CmdGUI.h
	LangtonAnt.cpp
)

add_executable(LangtonAnt ${SOURCES})

# TODO: Add tests and install targets if needed.
