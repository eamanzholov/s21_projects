CFLAGS = -Wall -Werror -Wextra -pedantic -std=c11 #-fsanitize=address
GCOVFLAGS = -fprofile-arcs -ftest-coverage
VALGRIND_FLAGS=--trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --verbose 
HEADERS = s21_matrix.h

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

%.o: %.c $(HEADERS)
	gcc $(CFLAGS) -c $< -o $@

PREF_TEST_SRC=./unit_tests/
TEST_SRC=$(wildcard $(PREF_TEST_SRC)/s21_*.c)

all: clean s21_matrix.a

s21_matrix.a: $(SRC)
	gcc -c $(CFLAGS) $(SRC)
	ar rcs s21_matrix.a $(OBJ)
	ranlib s21_matrix.a
	rm -rf *.o

test: clean s21_matrix.a tests/unit_test.c
	gcc $(CFLAGS) tests/unit_test.c s21_matrix.a -o test.out -lcheck -lsubunit -lm
	./test.out

test1: s21_matrix.a tests/unit_test1.c
	gcc $(CFLAGS) tests/unit_test1.c s21_matrix.a -o test1.out -lcheck -lsubunit -lm
	./test1.out

test2: clean s21_matrix.a
	gcc $(CFLAGS) ${TEST_SRC} s21_matrix.a -o test2.out -lcheck -lsubunit -lm
	./test2.out


gcov_report: s21_matrix.a tests/unit_test.c
	gcc $(CFLAGS) $(GCOVFLAGS) tests/unit_test.c $(SRC) -o report.out -lcheck -lsubunit -lm
	./report.out
	gcov -f *.gcda *.gcno
	lcov -t "gcov_report" -o Coverage_Report.info -c -d .
	genhtml -o ./report Coverage_Report.info
	xdg-open ./report/index.html || echo "Откройте вручную xdg-open ./report/index.html"
	rm -f *.gcno *.gcda *.info report.out *.gcov

gcov_report_1: clean s21_matrix.a tests/unit_test.c
	gcc $(CFLAGS) $(GCOVFLAGS) tests/unit_test.c $(SRC) -o report.out -lcheck -lsubunit -lm
	./report.out
	gcov -f *.gcda *.gcno
	lcov -t "gcov_report" -o Coverage_Report.info -c -d .
	genhtml -o ./report Coverage_Report.info
	@echo "Coverage report generated in ./report/app/index.html"
	rm -f *.gcno *.gcda *.info report.out *.gcov

clang:
	cp ../materials/linters/.clang-format ../src/.clang-format
	clang-format -style=Google -n ./*/*.c
	clang-format -style=Google -n *.c *.h

cpp:
	cppcheck —enable=all —suppress=missingIncludeSystem *.c *.h
	cd ./tests/ && cppcheck —enable=all —suppress=missingIncludeSystem *.c

valgrind: clean s21_matrix.a test
	valgrind --tool=memcheck --leak-check=yes  ./test.out

valg: 
	CK_FORK=no valgrind $(VALGRIND_FLAGS) --log-file=RESULT_VALGRIND.txt ./test.out
# gcc -g $(CFLAGS) ${TEST_SRC} s21_matrix.a -o test2.out -lcheck -lsubunit -lm

rebuild: clean all

docker_container:
	chmod +x run_coverage_report.sh
	./run_coverage_report.sh

clean:
	rm -f *.o *.a *.gcno *.gcda *.info *.out *.gcov
	rm -rf ./report

clean_cont: 
	rm -f *.o *.a *.gcno *.gcda *.info *.out *.gcov *.txt *.tar
	@sudo rm -rf ./report

.PHONY: all clean rebuild test gcov_report clang