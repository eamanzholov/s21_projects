#include <stdio.h>
#include <stdlib.h>

void readArray(int **a, int n);
void sortArray(int *a, int n);
void printArray(int *a, int n);

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("n/a");
        return 1;
    }

    int *a = malloc(n * sizeof(int));

    if (a == NULL) {
        printf("n/a");
        return 1;
    }

    readArray(&a, n);

    sortArray(a, n);

    printArray(a, n);

    free(a);

    return 0;
}

void readArray(int **a, int n) {
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &(*a)[i]) != 1) {
            printf("n/a");
            free(*a);
            exit(1);
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
        printf("%d", a[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
}
