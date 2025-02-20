# Compiler and flags
CC = gcc
CFLAGS = -Wall -ansi -pedantic -Werror -g -fno-common
OBJ = main.o game.o randomGen.o input.o rules.o sleep.o gameSavesLL.o
EXEC = eat

# Valgrind settings
VALGRIND_EXEC = valgrind
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes

# Default target
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) -lm

# Individual object files
main.o: main.c game.h rules.h gameSavesLL.h
	$(CC) $(CFLAGS) -c main.c

rules.o: rules.c rules.h
	$(CC) $(CFLAGS) -c rules.c

game.o: game.c game.h randomGen.h sleep.h input.h gameSavesLL.h
	$(CC) $(CFLAGS) -c game.c

input.o: input.c input.h game.h gameSavesLL.h
	$(CC) $(CFLAGS) -c input.c

randomGen.o: randomGen.c randomGen.h
	$(CC) $(CFLAGS) -c randomGen.c

sleep.o: sleep.c sleep.h
	$(CC) $(CFLAGS) -c sleep.c

gameSavesLL.o: gameSavesLL.c gameSavesLL.h game.h
	$(CC) $(CFLAGS) -c gameSavesLL.c

# Valgrind target
valgrind: $(EXEC)
	$(VALGRIND_EXEC) $(VALGRIND_FLAGS) ./$(EXEC) map.txt

# Clean target
clean:
	rm -f $(OBJ) $(EXEC)
