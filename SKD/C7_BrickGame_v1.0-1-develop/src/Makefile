CC = gcc
CFLAGS=-Wall -Werror -Wextra -std=c11 -I brick_game/tetris -I gui/cli -Wpedantic

TESTS=$(wildcard ./unit_tests/*.c)
OBJ_FSM := tetris.o tetris_fsm.o tetris_backend.o
OBJ_CLI := brick_game_frontend.o

INSTALL_DIR = ./bin

VERSION = 1.0
TARGET = tetris
DIST_DIR = $(TARGET)-$(VERSION)
DIST_SOURCES = ./Makefile ./unit_tests ./gui ./brick_game

all: clean tetris
	./tetris

install: clean tetris
	mkdir $(INSTALL_DIR)
	cp tetris $(INSTALL_DIR)

uninstall: clean
	rm -rf $(INSTALL_DIR)

dist: clean 
	mkdir -p $(DIST_DIR)
	cp -r $(DIST_SOURCES) $(DIST_DIR)
	tar -czf $(DIST_DIR).tar.gz $(DIST_DIR)
	rm -rf $(DIST_DIR)

dvi: clean doxy
	(cd ./doxygen/latex; sudo pdflatex refman.tex)
	
doxy: clean
	sudo doxygen

clean:
	rm -rf *.a *.o *.gcno *.gcda unit_test *.css *.html *.gcov tetris ./*/*/*.o
	rm -rf ./report *.gz

rebuild: clean all

tetris: tetris.a $(OBJ_CLI) main.o
	$(CC) $(CFLAGS)  $^ -o $@ tetris.a -lncurses

%.o: brick_game/tetris/%.c
	$(CC) $(CFLAGS)  -c $< -o $@

%.o: brick_game/%.c
	$(CC) $(CFLAGS)  -c $< -o $@

%.o: gui/cli/%.c
	$(CC) $(CFLAGS)  -c $< -o $@

%.o: brick_game/%.c
	$(CC) $(CFLAGS)  -c $< -o $@

tetris.a: $(OBJ_FSM)
	ar rc tetris.a $(OBJ_FSM)
	ranlib tetris.a

test: clean
	$(CC) $(CFLAGS)  $(TESTS) -c 
	$(CC) $(CFLAGS)  -o unit_test *.o ./brick_game/tetris/*.c --coverage -lcheck -lsubunit -lm
	chmod +x unit_test
	./unit_test

gcov_report: clean test
	gcov -f *.gcda *.gcno
	lcov -t "gcov_report" -o Coverage_Report.info -c -d .
	genhtml -o ./report Coverage_Report.info
	xdg-open ./report/index.html || echo "Откройте вручную xdg-open ./report/index.html"
	rm -f *.gcno *.gcda *.info report.out *.gcov

format:
	clang-format -n ./*/*/*.c ./*/*/*.h ./*/*.h *.c

formati:
	clang-format -i ./*/*/*.c ./*/*/*.h ./*/*.h ./*/*.c *.c

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem --std=c11 ./brick_game/tetris/*.h ./brick_game/tetris/*.c ./gui/cli/*.c ./gui/cli/*.h ./unit_tests/*.h ./unit_tests/*.c ./brick_game/*.h *.c

valgrind: test
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s  ./unit_test