#include "s21_matrix.h"

void calcMinor(double **A, double **aux, int skipRow, int skipCol, int size) {
  for (int row = 0, i = 0; row < size; row++) {
    for (int col = 0, j = 0; col < size; col++) {
      if (row != skipRow && col != skipCol) {
        aux[i][j++] = A[row][col];
        if (j == size - 1) {
          j = 0;
          i++;
        }
      }
    }
  }
}

double calcDeterminant(matrix_t *A, int size) {
  if (size == 1) return A->matrix[0][0];

  matrix_t aux = {0};
  double result = 0;

  s21_create_matrix(size, size, &aux);
  for (int sign = 1, i = 0; i < size; i++, sign *= (-1)) {
    calcMinor(A->matrix, aux.matrix, 0, i, size);
    result += sign * A->matrix[0][i] * calcDeterminant(&aux, size - 1);
  }

  s21_remove_matrix(&aux);
  return result;
}

int s21_determinant(matrix_t *A, double *result) {
  if (bad_matrix(A) == SUCCESS) return incorrect_matix;
  if (A->columns != A->rows) return calculation_error;

  if (A->rows == 1)
    *result = A->matrix[0][0];
  else
    *result = calcDeterminant(A, A->rows);

  return OK;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (bad_matrix(A) == SUCCESS) return incorrect_matix;
  if (A->columns != A->rows) return calculation_error;

  s21_create_matrix(A->columns, A->rows, result);
  if (A->rows != 1) {
    matrix_t aux = {0};

    s21_create_matrix(A->rows, A->rows, &aux);
    for (int sign = 0, i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        calcMinor(A->matrix, aux.matrix, i, j, A->rows);
        sign = ((i + j) % 2 == 0) ? 1 : (-1);
        result->matrix[i][j] = sign * calcDeterminant(&aux, A->rows - 1);
      }
    }

    s21_remove_matrix(&aux);
  } else {
    result->matrix[0][0] = 1;
  }

  return OK;
}
