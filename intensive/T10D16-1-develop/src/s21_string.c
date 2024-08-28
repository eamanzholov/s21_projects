#include "s21_string.h"

#include <stdlib.h>

size_t s21_strlen(const char *str) {
    size_t length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}
int s21_strcmp(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

void s21_strcpy(char *dest, const char *src) {
    while (*src != '\0') {
        *dest = *src;
        ++dest;
        ++src;
    }
    *dest = '\0';
}
void s21_strcat(char *dest, const char *src) {
    while (*dest != '\0') {
        ++dest;
    }

    while (*src != '\0') {
        *dest = *src;
        ++dest;
        ++src;
    }

    *dest = '\0';
}
char *s21_strchr(const char *str, int character) {
    while (*str != '\0' && *str != character) {
        ++str;
    }

    if (*str == character) {
        return (char *)str;
    } else {
        return NULL;
    }
}

const char *s21_strstr(const char *haystack, const char *needle) {
    if (*needle == '\0') {
        return haystack;
    }

    while (*haystack) {
        const char *h = haystack;
        const char *n = needle;

        while (*h && *n && (*h == *n)) {
            h++;
            n++;
        }

        if (*n == '\0') {
            return haystack;
        }

        haystack++;
    }

    return NULL;
}

char *s21_strtok(const char *str, const char *delim) {
    static const char *lastToken = NULL;

    if (str != NULL) {
        lastToken = str;
    } else if (lastToken == NULL) {
        return NULL;
    }

    size_t delimLength = s21_strlen(delim);

    if (delimLength == 0) {
        return NULL;
    }

    const char *tokenStart = lastToken;

    while (*lastToken != '\0') {
        int isDelimiter = 0;
        for (size_t i = 0; i < delimLength; ++i) {
            if (*lastToken == delim[i]) {
                isDelimiter = 1;
                break;
            }
        }

        if (isDelimiter) {
            if (tokenStart != lastToken) {
                char *token = malloc(lastToken - tokenStart + 1);
                if (token == NULL) {
                    return NULL;
                }
                s21_strcpy(token, tokenStart);
                token[lastToken - tokenStart] = '\0';
                return token;
            } else {
                ++lastToken;
                tokenStart = lastToken;
            }
        } else {
            ++lastToken;
        }
    }

    if (tokenStart != lastToken) {
        char *token = malloc(lastToken - tokenStart + 1);
        if (token == NULL) {
            return NULL;
        }
        s21_strcpy(token, tokenStart);
        token[lastToken - tokenStart] = '\0';
        return token;
    }

    return NULL;
}