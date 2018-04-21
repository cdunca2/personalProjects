OBJS = hellosdl.cpp

CC = g++

COMPILER_FLAGS = -Wall -g -std=c++11

LINKER_FLAGS = -lSDL2 -lSDL2_image

OBJ_NAME = runner

all : $(OBJS)
	$(CC) $(COMPILER_FLAGS) $(OBJS) $(LINKER_FLAGS) -o $(OBJ_NAME)

clean:
	rm -f runner
