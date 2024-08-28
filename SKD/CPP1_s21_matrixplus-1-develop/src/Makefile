CC = g++
CFLAGS=-Wall -Werror -Wextra -std=c++17 -Wpedantic

SOURCES = s21_matrix_oop.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: clean test

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.a *.o *.css *.gcda *.gcno *.html main unit_test
	rm -rf ./report

s21_matrix_oop.a: $(OBJECTS)
	ar rcs $@ $^

test:
	$(CC) $(CFLAGS) unit_test.cpp -c 
	$(CC) $(CFLAGS) -o unit_test unit_test.o s21_matrix_oop.cpp --coverage -lgtest -lgtest_main
	./unit_test

gcov_report: test
	gcov -f *.gcda *.gcno
	lcov -t "gcov_report" -o Coverage_Report.info -c -d .
	genhtml -o ./report Coverage_Report.info
	open ./report/index.html
	rm -f *.gcno *.gcda *.info report.out *.gcov

gcov_report1: test
	./unit_test
	mkdir -p report
	gcov *.c
	gcov *.gcda report/
	mv *.gcov report/
	~/.local/bin/gcovr -r . --html --html-details -o report/index.html --gcov-ignore-parse-errors 
	open ./report/index.html
	rm -f *.gcno *.gcda *.info report.out *.gcov

format:
	cp ../materials/linters/.clang-format ./
	clang-format -n *.cpp *.h

formati:
	clang-format -i *.cpp *.h

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem --std=c++17 --language=c++ *.cpp *.h

valgrind: clean test
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s  ./unit_test