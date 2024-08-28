#include <stdio.h>

#define MAX_SIZE 10

void input(int *array, int *n);
void output(int *array, int n);
void cycle_shift(int *array, int n, int shift);

int main() {
    int n, array[MAX_SIZE], shift;

    input(array, &n);
    scanf("%d", &shift);

    cycle_shift(array, n, shift);
    output(array, n);

    return 0;
}

void input(int *array, int *n) {
    scanf("%d", n);

    if (*n < 1 || *n > MAX_SIZE) {
        printf("n/a\n");
    }

    for (int i = 0; i < *n; ++i) {
        scanf("%d", &array[i]);
    }
}

void output(int *array, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void cycle_shift(int *array, int n, int shift) {
    shift = shift % n;

    if (shift < 0) {
        shift += n;
    }

    int temp[MAX_SIZE];

    for (int i = 0; i < n; ++i) {
        temp[i] = array[(i + shift) % n];
    }

    for (int i = 0; i < n; ++i) {
        array[i] = temp[i];
    }
}
