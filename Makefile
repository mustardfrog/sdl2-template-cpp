CC=g++
SRCS=main.cpp Game.cpp Ball.cpp
FLAGS=-lSDL2 -lSDL2_image

main: $(SRCS)
	$(CC) $(SRCS) -o main $(FLAGS)
