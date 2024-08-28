#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int status = bad_matrix(A);

  if (status == 0 &&
      (status = s21_create_matrix(A->columns, A->rows, result)) == 0) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }

  return status;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (bad_matrix(A) == SUCCESS) return incorrect_matix;
  if (A->columns != A->rows) return calculation_error;

  double det = 0;
  int status = s21_determinant(A, &det);
  if (fabs(det) < 1e-6 || status != OK) return calculation_error;
  matrix_t aux = {0}, aux_transpose = {0};

  s21_calc_complements(A, &aux);
  s21_transpose(&aux, &aux_transpose);
  s21_create_matrix(A->rows, A->rows, result);

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->rows; j++) {
      result->matrix[i][j] = aux_transpose.matrix[i][j] / det;
    }
  }

  s21_remove_matrix(&aux_transpose);
  s21_remove_matrix(&aux);
  return OK;
}