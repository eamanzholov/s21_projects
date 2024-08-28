#include <stdio.h>

#define LEN 100

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);

void input(int *buff, int *length);
void output(int *buff, int length);

int main() {
    int buff1[LEN], buff2[LEN], result[LEN * 2];
    int len1, len2, result_length;

    input(buff1, &len1);
    input(buff2, &len2);

    sum(buff1, len1, buff2, len2, result, &result_length);
    output(result, result_length);

    sub(buff1, len1, buff2, len2, result, &result_length);
    output(result, result_length);

    return 0;
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int carry = 0;
    int max_len = len1 > len2 ? len1 : len2;

    for (int i = 0; i < max_len; i++) {
        int num1 = i < len1 ? buff1[i] : 0;
        int num2 = i < len2 ? buff2[i] : 0;

        int digit_sum = num1 + num2 + carry;
        result[i] = digit_sum % 10;
        carry = digit_sum / 10;
    }

    if (carry > 0) {
        result[max_len] = carry;
        *result_length = max_len + 1;
    } else {
        *result_length = max_len;
    }
}

void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    if (len1 < len2) {
        *result_length = 1;
        result[0] = 0;
        printf("n/a\n");
        return;
    }

    int borrow = 0;

    for (int i = 0; i < len1; i++) {
        int num1 = buff1[i];
        int num2 = i < len2 ? buff2[i] : 0;

        int digit_diff = num1 - num2 - borrow;

        if (digit_diff < 0) {
            digit_diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result[i] = digit_diff;
    }

    while (*result_length > 1 && result[*result_length - 1] == 0) {
        (*result_length)--;
    }
}
void input(int *buff, int *length) {
    scanf("%d", length);
    for (int i = 0; i < *length; i++) {
        scanf("%d", &buff[i]);
    }
}

void output(int *buff, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", buff[i]);
    }
    printf("\n");
}
