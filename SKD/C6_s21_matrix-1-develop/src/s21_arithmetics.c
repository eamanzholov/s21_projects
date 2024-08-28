#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return simpleArithmetics(A, B, result, 1);
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return simpleArithmetics(A, B, result, 2);
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = (bad_matrix(A) || bad_matrix(B));

  if (status == 0 && (status = A->columns != B->rows ? 2 : 0) == 0) {
    if ((status = s21_create_matrix(A->rows, B->columns, result)) == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          for (int k = 0; k < B->rows; k++)
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }

  return status;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int status = bad_matrix(A);

  if (status == 0 &&
      (status = s21_create_matrix(A->rows, A->columns, result)) == 0) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++)
        result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }

  return status;
}

int simpleArithmetics(matrix_t *A, matrix_t *B, matrix_t *result, int sign) {
  int status = bad_eq_matrix(A, B);

  if (status == 0 &&
      (status = s21_create_matrix(A->rows, A->columns, result)) == 0) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (sign == 1)
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        else if (sign == 2)
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }

  return status;
}