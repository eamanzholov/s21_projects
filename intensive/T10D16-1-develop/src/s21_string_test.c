#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

void s21_strlen_test(const char *input, size_t expected) {
    size_t result = s21_strlen(input);
    printf("Input: %s\n", input);
    printf("Expected Output: %lu\n", expected);
    printf("Actual Output: %lu\n", result);
    printf("Result: %s\n\n", (result == expected) ? "SUCCESS" : "FAIL");
}

void s21_strcmp_test(const char *str1, const char *str2, int expected) {
    int result = s21_strcmp(str1, str2);
    printf("Input: %s, %s\n", str1, str2);
    printf("Expected Output: %d\n", expected);
    printf("Actual Output: %d\n", result);
    printf("Result: %s\n\n", (result == expected) ? "SUCCESS" : "FAIL");
}

void s21_strcpy_test(const char *src, const char *expected) {
    char dest[100];

    s21_strcpy(dest, src);

    printf("Input: %s\n", src);
    printf("Expected Output: %s\n", expected);
    printf("Actual Output: %s\n", dest);
    printf("Result: %s\n\n", (s21_strcmp(dest, expected) == 0) ? "SUCCESS" : "FAIL");
}

void s21_strcat_test(const char *dest, const char *src, const char *expected) {
    char result[100];
    s21_strcpy(result, dest);

    s21_strcat(result, src);

    printf("Input: %s, %s\n", dest, src);
    printf("Expected Output: %s\n", expected);
    printf("Actual Output: %s\n", result);
    printf("Result: %s\n\n", (s21_strcmp(result, expected) == 0) ? "SUCCESS" : "FAIL");
}

void s21_strchr_test(const char *str, int character, const char *expected) {
    char *result = s21_strchr(str, character);

    printf("Input: %s, %c\n", str, character);
    printf("Expected Output: %s\n", expected);
    printf("Actual Output: %s\n", (result != NULL) ? result : "NULL");
    printf("Result: %s\n\n",
           ((result != NULL && *result == *expected) || (result == NULL && *expected == '\0')) ? "SUCCESS"
                                                                                               : "FAIL");
}

void s21_strstr_test(const char *haystack, const char *needle, const char *expected) {
    const char *result = s21_strstr(haystack, needle);
    printf("Input: %s, %s\n", haystack, needle);
    printf("Expected Output: %s\n", expected);
    printf("Actual Output: %s\n", result);
    printf("Result: %s\n\n", (result == expected) ? "SUCCESS" : "FAIL");
}

void s21_strtok_test(const char *str, const char *delim, const char *expected) {
    char *result = s21_strtok(str, delim);
    printf("Input: str='%s', delim='%s'\n", str, delim);
    printf("Expected Output: '%s'\n", expected);
    printf("Actual Output: '%s'\n", result);
    printf("Result: %s\n\n", (result && s21_strcmp(result, expected) == 0) ? "SUCCESS" : "FAIL");
}

int main() {
#ifdef STRLEN
    s21_strlen_test("", 0);
    s21_strlen_test("Hello, World!", 13);
    s21_strlen_test("12345", 5);
#endif
#ifdef STRCMP
    s21_strcmp_test("abc", "abc", 0);
    s21_strcmp_test("abc", "abcd", -1);
    s21_strcmp_test("abcd", "abc", 1);
#endif
#ifdef STRCPY
    s21_strcpy_test("source", "source");
    s21_strcpy_test("", "");
    s21_strcpy_test("long source string", "long source string");
#endif
#ifdef STRCAT
    s21_strcat_test("Hello, ", "World!", "Hello, World!");
    s21_strcat_test("", "", "");
    s21_strcat_test("Number: ", "123", "Number: 123");
#endif
#ifdef STRCHR
    s21_strchr_test("abcdef", 'c', "cdef");
    s21_strchr_test("abcdef", 'g', "");
    s21_strchr_test("", 'a', "");
#endif
#ifdef STRSTR
    s21_strstr_test("Hello, World!", "World", "World!");
    s21_strstr_test("Hello, World!", "123", NULL);
    s21_strstr_test("Hello, World!", "Hello", "Hello, World!");
    s21_strstr_test("Hello, World!", "!", "!");
#endif
#ifdef STRTOK
    s21_strtok_test("apple,orange,banana", ",", "apple");
    s21_strtok_test("apple,orange,banana", "123", NULL);
    s21_strtok_test("apple,orange,banana", "a", "");
    s21_strtok_test("apple,orange,banana", ",", "apple");
#endif
    return 0;
}
