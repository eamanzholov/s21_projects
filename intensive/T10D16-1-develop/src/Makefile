CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -c
BUILD_DIR = ../build

strtok_tests: s21_string.o s21_string_test.c
	$(CC) $(CFLAGS) -D STRTOK s21_string_test.c
	$(CC) s21_string.o s21_string_test.o -o $(BUILD_DIR)/Quest_7

strstr_tests: s21_string.o s21_string_test.c
	$(CC) $(CFLAGS) -D STRSTR s21_string_test.c
	$(CC) s21_string.o s21_string_test.o -o $(BUILD_DIR)/Quest_6

strchr_tests: s21_string.o s21_string_test.c
	$(CC) $(CFLAGS) -D STRCHR s21_string_test.c
	$(CC) s21_string.o s21_string_test.o -o $(BUILD_DIR)/Quest_5

strcat_tests: s21_string.o s21_string_test.c
	$(CC) $(CFLAGS) -D STRCAT s21_string_test.c
	$(CC) s21_string.o s21_string_test.o -o $(BUILD_DIR)/Quest_4

strcpy_tests: s21_string.o s21_string_test.c
	$(CC) $(CFLAGS) -D STRCPY s21_string_test.c
	$(CC) s21_string.o s21_string_test.o -o $(BUILD_DIR)/Quest_3

strcmp_tests: s21_string.o s21_string_test.c
	$(CC) $(CFLAGS) -D STRCMP s21_string_test.c
	$(CC) s21_string.o s21_string_test.o -o $(BUILD_DIR)/Quest_2

strlen_tests: s21_string.o s21_string_test.c
	$(CC) $(CFLAGS) -D STRLEN s21_string_test.c
	$(CC) s21_string.o s21_string_test.o -o $(BUILD_DIR)/Quest_1

s21_string.o:
	$(CC) $(CFLAGS) s21_string.c

clean:
	rm -f *.o
	rm -f $(BUILD_DIR)/Quest*
