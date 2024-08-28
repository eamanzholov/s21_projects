#include <stdio.h>

void input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

int main() {
    int buffer[10], length;

    input(buffer, &length);

    int summ = sum_numbers(buffer, length);

    if (summ == 0) {
        printf("n/a\n");
        return 0;
    }

    int result[10];
    int result_length = find_numbers(buffer, length, summ, result);

    output(result, result_length);

    return 0;
}

void input(int *buffer, int *length) {
    scanf("%d", length);
    for (int i = 0; i < *length; i++) {
        scanf("%d", &buffer[i]);
    }
}

void output(int *buffer, int length) {
    printf("%d\n", sum_numbers(buffer, length));
    for (int i = 0; i < length; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");
}

int sum_numbers(int *buffer, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum += buffer[i];
        }
    }
    return sum;
}

int find_numbers(int *buffer, int length, int number, int *numbers) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] % number == 0) {
            numbers[count++] = buffer[i];
        }
    }
    return count;
}
