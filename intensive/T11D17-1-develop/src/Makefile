CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -c
BUILD_DIR = ../build

all: door_struct list_test stack_test

stack_test: stack_test.o stack.o stack.h
	$(CC) stack_test.o stack.o stack.h -o $(BUILD_DIR)/Quest_3

stack.o:
	$(CC) $(CFLAGS) stack.c stack.h

stack_test.o:
	$(CC) $(CFLAGS) stack_test.c stack.h

list_test: list.o list_test.o door_struct.h
	$(CC) list.o list_test.o door_struct.h -o $(BUILD_DIR)/Quest_2

list.o:
	$(CC) $(CFLAGS) list.c list.h

list_test.o:
	$(CC) $(CFLAGS) list_test.c list.h

door_struct: door_struct.h dmanager_module.o
	$(CC) door_struct.h dmanager_module.o -o $(BUILD_DIR)/Quest_1

clean:
	rm -f *.o
	rm -f $(BUILD_DIR)/Quest*

rebuild: clean all
