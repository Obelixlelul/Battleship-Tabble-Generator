cmake_minimum_required(VERSION 2.8.9)
project(BattleshipPuzzleGenerator)

#Bring the headers, such as Student.h into the project
include_directories(include)

#Can manually add the sources using the ser command as follows:
#set(SOURCES src/main.cpp src/searching.cpp)

#However, the file (Glob...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")

add_executable(bpg ${SOURCES})

#To create cmake inside the build folder when its not working in tradicional methods
#cmake -S . -Bbuild