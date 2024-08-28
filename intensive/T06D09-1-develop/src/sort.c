#include <stdio.h>
#define NMAX 10

void readArray(int *a, int n);
void sortArray(int *a, int n);
void printArray(int *a, int n);

int main() {
    int a[NMAX];

    readArray(a, NMAX);

    sortArray(a, NMAX);

    printArray(a, NMAX);

    return 0;
}

void readArray(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            printf("n/a");
        }
    }
}

void sortArray(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void printArray(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}