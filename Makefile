CC=gcc
CFLAGS=-I. -Wall
DEPS = shell.h
OBJ = main.o prompt.o parse.o execute.o builtins.o path.o environment.o helpers.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

shell: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
