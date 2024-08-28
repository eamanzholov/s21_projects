#ifndef S21_STRING_H
#define S21_STRING_H
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef unsigned long size_t;
size_t s21_strlen(const char *str);
int s21_strcmp(const char *str1, const char *str2);
void s21_strcpy(char *dest, const char *src);
void s21_strcat(char *dest, const char *src);
char *s21_strchr(const char *str, int character);
const char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(const char *str, const char *delim);

#endif
