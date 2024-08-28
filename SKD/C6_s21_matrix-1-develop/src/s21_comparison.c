#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = bad_eq_matrix(A, B) == 0;

  for (int i = 0; status == 1 && i < A->rows; i++) {
    for (int j = 0; status == 1 && j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-07) status = FAILURE;
    }
  }

  return status;
}

int bad_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = 1;

  if (bad_matrix(A) == 0) {
    if (bad_matrix(B) == 0)
      status = (A->rows == B->rows && A->columns == B->columns) ? 0 : 2;
  }

  return status;
}

int bad_matrix(matrix_t *A) {
  return (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0);
}