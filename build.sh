#! /bin/sh

g++ src/main.cpp src/Game.cpp src/MovingBox.cpp src/Shapes.cpp -lSDL2 -lSDL2_image -o main
