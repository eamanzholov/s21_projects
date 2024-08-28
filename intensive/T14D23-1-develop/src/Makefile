
CFLAGS = -Wall -Werror -Wextra -std=c11
BUILD = ../build

all: state_sort state_search clear_state

clear_state:
	gcc -Wall -Werror -Wextra -std=c11 -D_POSIX_C_SOURCE=200809L clear_state.c -o $(BUILD)/Quest_3

state_search: state_search.c
	gcc $(CFLAGS) state_search.c -o $(BUILD)/Quest_2

state_sort: state_sort.c
	gcc $(CFLAGS) state_sort.c -o $(BUILD)/Quest_1

clang:
	@clang-format -i state_sort.c

cpp:
	@cppcheck --enable=all --suppress=missingIncludeSystem ../src/

valgrind:
	@valgrind --tool=memcheck --leak-check=yes  ../build/./Quest*

start:
	../build/./Quest*

clean:
	rm -f *.o
	rm -f $(BUILD)/Quest*

rebuild: clean all
