CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
BUILD_DIR = ../build

all: print_module documentation_module bst_create_test bst_insert_test

print_module: main_module_entry_point.c print_module.c
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/Quest_1 main_module_entry_point.c print_module.c -D print_module

documentation_module: main_module_entry_point.c documentation_module.c
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/Quest_2 main_module_entry_point.c documentation_module.c -D documentation_module

bst_create_test: bst_create_test.c bst.c
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/Quest_3 bst.c bst_create_test.c

bst_insert_test: bst_insert_test.c bst.c
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/Quest_4 bst.c bst_insert_test.c

clang:
	@clang-format -i main_module_entry_point.c print_module.h print_module.c documentation_module.c documentation_module.h

cpp:
	@cppcheck --enable=all --suppress=missingIncludeSystem ../src/

valgrind:
	@valgrind --tool=memcheck --leak-check=yes  ../build/./Quest*

start:
	../build/./Quest*

clean:
	rm -f *.o
	rm -f $(BUILD_DIR)/Quest*

rebuild: clean all
