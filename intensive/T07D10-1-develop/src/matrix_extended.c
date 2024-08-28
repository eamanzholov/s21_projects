#include <stdio.h>
#include <stdlib.h>

// Статическое выделение памяти
int static_matrix[100][100];
int **Matrix_2(int n, int m);
void freeMatrix_2(int **matrix, int n);
int **Matrix_3(int n, int m);
void freeMatrix_3(int **matrix);
int **Matrix_4(int n, int m); 
void freeMatrix_4(int **matrix);
int input(int **matrix, int *n, int *m);
void output(int **matrix, int n, int m);
void findMin(int **matrix, int n, int m);

int main() {
    int choice;
    int n, m;
    int **matrix;

    if (scanf("%d", &choice) != 1 || choice < 1 || choice > 4) {
        printf("n/a");
        return 1;
    }
    // Выбор функции для статического или динамического выделения памяти
    switch (choice) {
        case 1:
            n = 100;
            m = 100;
            matrix = (int **)malloc(n * sizeof(int *));
            for (int i = 0; i < n; i++) {
                matrix[i] = (int *)malloc(m * sizeof(int));
            }
            break;
        case 2:
            matrix = Matrix_2(100, 100);
            break;
        case 3:
            matrix = Matrix_3(100, 100);
            break;
        case 4:
            matrix = Matrix_4(100, 100);
            break;
        default:
            printf("n/a");
            return 1;
    }

    if (!input(matrix, &n, &m)) {
        // Ошибка при вводе матрицы
        if (choice != 1) {
            switch (choice) {
                case 2:
                    freeMatrix_2(matrix, n);
                    break;
                case 3:
                    freeMatrix_3(matrix);
                    break;
                case 4:
                    freeMatrix_4(matrix);
                    break;
            }
        }
        return 1;
    }

    output(matrix, n, m);

    // Освобождение памяти
    if (choice != 1) {
        switch (choice) {
            case 2:
                freeMatrix_2(matrix, n);
                break;
            case 3:
                freeMatrix_3(matrix);
                break;
            case 4:
                freeMatrix_4(matrix);
                break;
        }
    }
    return 0;
}
// Функция для динамического выделения памяти 2
int **Matrix_2(int n, int m) {
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(m * sizeof(int));
    }
    return matrix;
}

// Функция для освобождения памяти, выделенной динамически 2
void freeMatrix_2(int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    // free(matrix[0]);
    free(matrix);
}

// Функция для динамического выделения памяти 3
int **Matrix_3(int n, int m) {
    int **matrix = malloc(m * n * sizeof(int) + n * sizeof(int *));
    int *ptr = (int *)(matrix + n);

    for (int i = 0; i < n; i++) {
        matrix[i] = ptr + m * i;
    }
    return matrix;
}
// Функция для освобождения памяти, выделенной динамически 3
void freeMatrix_3(int **matrix) { free(matrix); }
// Функция для динамического выделения памяти 4
int **Matrix_4(int n, int m) {
    int **matrix = malloc(n * sizeof(int *));
    int *array_matrix = malloc(n * m * sizeof(int));

    for (int i = 0; i < n; i++) {
        matrix[i] = array_matrix + m * i;
    }
    return matrix;
}

// Функция для освобождения памяти, выделенной динамически 3
void freeMatrix_4(int **matrix) {
    free(matrix[0]);
    free(matrix);
}

// Функция для ввода матрицы
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

// Функция для вывода матрицы
void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", matrix[i][j]);
            if (j < m - 1) {
                printf(" ");
            }
        }
        if (i < n) {
            printf("\n");
        }
    }
    // находим макс элемент в строках
    int max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (max < matrix[i][j]) {
                max = matrix[i][j];
            }
        }
        printf("%d", max);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
    // находим мин элемент в столбцах
    findMin(matrix, n, m);
}
void findMin(int **matrix, int n, int m) {
    // Инициализация массива минимальных значений для каждого столбца
    int minValues[m];

    // Инициализация массива минимальных значений нулями
    for (int j = 0; j < m; j++) {
        minValues[j] = matrix[0][j];
    }

    // Поиск минимальных значений в каждом столбце
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] < minValues[j]) {
                minValues[j] = matrix[i][j];
            }
        }
    }
    // Вывод минимальных значений

    for (int j = 0; j < m; j++) {
        printf("%d", minValues[j]);
        if (j < m - 1) {
            printf(" ");
        }
    }
}