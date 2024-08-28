CFLAGS = -Wall -Werror -Wextra -std=c11
BUILD = ../build/


all: cipher

cipher: cipher.c
	gcc $(CFLAGS) cipher.c -o $(BUILD)cipher

clean:
	rm -f *.gch
	rm -f *.o
	rm -f $(BUILD)cipher

rebuild: clean all

start:
	$(BUILD)./cipher

cpp:
	@cppcheck --enable=all --suppress=missingIncludeSystem ../src/

valgrind:
	@valgrind --tool=memcheck --leak-check=yes $(BUILD)./cipher
