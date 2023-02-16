CC=g++
SRCS=src/main.cpp src/Game.cpp src/MovingBox.cpp src/Shapes.cpp
FLAGS=-lSDL2 -lSDL2_image
WARNS=-Wall -Wextra

main: $(SRCS)
	$(CC) $(SRCS) -o main $(FLAGS) $(WARNS)

notmain: notMain.cpp
	$(CC) notMain.cpp -o not $(FLAGS) $(WARNS)
