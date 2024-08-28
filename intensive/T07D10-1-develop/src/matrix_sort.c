#include <stdio.h>
#include <stdlib.h>

int input(int **matrix, int *n, int *m);
void printMatrix(int **matrix, int n, int m);
void sortMatrix(int **matrix, int n, int m);
int calculate(int *n, int m);
int **Matrix_1(int n, int m);
void freeMatrix_1(int **matrix, int n);
int **Matrix_2(int n, int m);
void freeMatrix_2(int **matrix);
int **Matrix_3(int n, int m);
void freeMatrix_3(int **matrix);

int main() {
    int choice;
    int n, m;
    int **matrix;

    if (scanf("%d", &choice) != 1 || choice < 1 || choice > 3) {
        printf("n/a");
        return 1;
    }
    // Выбор функции для динамического выделения памяти
    switch (choice) {
        case 1:
            matrix = Matrix_1(100, 100);
            break;
        case 2:
            matrix = Matrix_2(100, 100);
            break;
        case 3:
            matrix = Matrix_3(100, 100);
            break;
        default:
            printf("n/a");
            return 1;
    }

    if (!input(matrix, &n, &m)) {
        // Ошибка при вводе матрицы
        if (choice != 1) {
            switch (choice) {
                case 1:
                    freeMatrix_1(matrix, n);
                    break;
                case 2:
                    freeMatrix_2(matrix);
                    break;
                case 3:
                    freeMatrix_3(matrix);
                    break;
            }
        }
        return 1;
    }

    // Сортировка матрицы
    sortMatrix(matrix, n, m);

    // Вывод отсортированной матрицы
    printMatrix(matrix, n, m);

    // Освобождение памяти
    switch (choice) {
        case 1:
            freeMatrix_1(matrix, n);
            break;
        case 2:
            freeMatrix_2(matrix);
            break;
        case 3:
            freeMatrix_3(matrix);
            break;
    }

    return 0;
}

int input(int **matrix, int *n, int *m) {
    if (scanf("%d %d", n, m) != 2 || *n <= 0 || *m <= 0 || *n > 100 || *m > 100) {
        printf("n/a");
        return 0;
    }

    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("n/a");
                return 0;
            }
        }
    }
    return 1;
}

void printMatrix(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", matrix[i][j]);
            if (j < m - 1) {
                printf(" ");
            }
        }
        if (i < n - 1) {
            printf("\n");
        }
    }
}

void sortMatrix(int **matrix, int n, int m) {
    // Сортировка матрицы по суммам строк
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int sumI = calculate(matrix[i], m);
            int sumJ = calculate(matrix[j], m);

            if (sumI > sumJ) {
                // Обмен строк
                int *temp = matrix[i];
                matrix[i] = matrix[j];
                matrix[j] = temp;
            }
        }
    }
}

int calculate(int *n, int m) {
    // Вычисление суммы элементов строки
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += n[i];
    }
    return sum;
}
// Функция для динамического выделения памяти 1
int **Matrix_1(int n, int m) {
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(m * sizeof(int));
    }
    return matrix;
}

// Функция для освобождения памяти, выделенной динамически 1
void freeMatrix_1(int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    // free(matrix[0]);
    free(matrix);
}

// Функция для динамического выделения памяти 2
int **Matrix_2(int n, int m) {
    int **matrix = malloc(m * n * sizeof(int) + n * sizeof(int *));
    int *ptr = (int *)(matrix + n);

    for (int i = 0; i < n; i++) {
        matrix[i] = ptr + m * i;
    }
    return matrix;
}
// Функция для освобождения памяти, выделенной динамическ 2
void freeMatrix_2(int **matrix) { free(matrix); }
// Функция для динамического выделения памяти 4
int **Matrix_3(int n, int m) {
    int **matrix = malloc(n * sizeof(int *));
    int *array_matrix = malloc(n * m * sizeof(int));

    for (int i = 0; i < n; i++) {
        matrix[i] = array_matrix + m * i;
    }
    return matrix;
}

// Функция для освобождения памяти, выделенной динамически 3
void freeMatrix_3(int **matrix) {
    free(matrix[0]);
    free(matrix);
}
