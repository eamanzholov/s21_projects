#include <stdio.h>
#include <stdlib.h>

int input(int ***matrix, int *n, int *m);
void output(int **matrix, int n, int m);
int sum(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int ***matrix_result, int *n_result, int *m_result);
int transpose(int **matrix, int n, int m);
int mul(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int ***matrix_result, int *n_result, int *m_result);

int main() {
    int operation;
    if (scanf("%d", &operation) != 1 || (operation < 1 || operation > 3)) {
        printf("n/a");
        return 1;
    }

    int n_first, m_first, n_second, m_second;
    int **matrix_first, **matrix_second, **matrix_result;
    int n_result, m_result;

    if (input(&matrix_first, &n_first, &m_first) || input(&matrix_second, &n_second, &m_second)) {
        printf("n/a");
        return 1;
    }

    switch (operation) {
        case 1:
            if (sum(matrix_first, n_first, m_first, matrix_second, n_second, m_second, &matrix_result,
                    &n_result, &m_result)) {
                printf("n/a");
                return 1;
            }
            break;
        case 2:
            if (mul(matrix_first, n_first, m_first, matrix_second, n_second, m_second, &matrix_result,
                    &n_result, &m_result)) {
                printf("n/a");
                return 1;
            }
            break;
        case 3:
            if (transpose(matrix_first, n_first, m_first)) {
                printf("n/a");
                return 1;
            }
            break;
        default:
            printf("n/a");
            return 1;
    }

    output(matrix_result, n_result, m_result);

    for (int i = 0; i < n_first; i++) {
        free(matrix_first[i]);
    }
    free(matrix_first);

    for (int i = 0; i < n_second; i++) {
        free(matrix_second[i]);
    }
    free(matrix_second);

    if (matrix_result) {
        for (int i = 0; i < n_result; i++) {
            free(matrix_result[i]);
        }
        free(matrix_result);
    }

    return 0;
}

int input(int ***matrix, int *n, int *m) {
    if (scanf("%d %d", n, m) != 2 || *n <= 0 || *m <= 0) {
        return 1;
    }

    *matrix = (int **)malloc(*n * sizeof(int *));
    if (!*matrix) {
        return 1;
    }

    for (int i = 0; i < *n; i++) {
        (*matrix)[i] = (int *)malloc(*m * sizeof(int));
        if (!(*matrix)[i]) {
            for (int j = 0; j < i; j++) {
                free((*matrix)[j]);
            }
            free(*matrix);
            return 1;
        }

        for (int j = 0; j < *m; j++) {
            if (scanf("%d", &(*matrix)[i][j]) != 1) {
                for (int k = 0; k <= i; k++) {
                    free((*matrix)[k]);
                }
                free(*matrix);
                return 1;
            }
        }
    }

    return 0;
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int sum(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int ***matrix_result, int *n_result, int *m_result) {
    if (n_first != n_second || m_first != m_second) {
        return 1;
    }

    *n_result = n_first;
    *m_result = m_first;

    *matrix_result = (int **)malloc(*n_result * sizeof(int *));
    if (!*matrix_result) {
        return 1;
    }

    for (int i = 0; i < *n_result; i++) {
        (*matrix_result)[i] = (int *)malloc(*m_result * sizeof(int));
        if (!(*matrix_result)[i]) {
            for (int j = 0; j < i; j++) {
                free((*matrix_result)[j]);
            }
            free(*matrix_result);
            return 1;
        }

        for (int j = 0; j < *m_result; j++) {
            (*matrix_result)[i][j] = matrix_first[i][j] + matrix_second[i][j];
        }
    }

    return 0;
}

int transpose(int **matrix, int n, int m) {
    int **transposed_matrix = (int **)malloc(m * sizeof(int *));
    if (!transposed_matrix) {
        return 1;
    }

    for (int i = 0; i < m; i++) {
        transposed_matrix[i] = (int *)malloc(n * sizeof(int));
        /*if (!transposed_matrix[i]) {
            for (int j = 0; j < i; j++) {
                free(transposed_matrix[j]);
            }
            free(transposed_matrix);
            return 1;
        }*/

        for (int j = 0; j < n; j++) {
            transposed_matrix[i][j] = matrix[j][i];
        }
    }

    output(transposed_matrix, m, n);

    for (int i = 0; i < m; i++) {
        free(transposed_matrix[i]);
    }
    free(transposed_matrix);

    return 0;
}

int mul(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int ***matrix_result, int *n_result, int *m_result) {
    if (m_first != n_second) {
        return 1;
    }

    *n_result = n_first;
    *m_result = m_second;

    *matrix_result = (int **)malloc(*n_result * sizeof(int *));
    if (!*matrix_result) {
        return 1;
    }

    for (int i = 0; i < *n_result; i++) {
        (*matrix_result)[i] = (int *)malloc(*m_result * sizeof(int));
        if (!(*matrix_result)[i]) {
            for (int j = 0; j < i; j++) {
                free((*matrix_result)[j]);
            }
            free(*matrix_result);
            return 1;
        }

        for (int j = 0; j < *m_result; j++) {
            (*matrix_result)[i][j] = 0;
            for (int k = 0; k < m_first; k++) {
                (*matrix_result)[i][j] += matrix_first[i][k] * matrix_second[k][j];
            }
        }
    }

    return 0;
}
