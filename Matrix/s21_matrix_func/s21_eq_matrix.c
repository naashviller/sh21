#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int return_value = -1;

  if ((s21_matrix_ptr_is_null(A) == 1) || (s21_matrix_ptr_is_null(B) == 1) ||
      (s21_matrix_sizes_le_zero(A) == 1) ||
      (s21_matrix_sizes_le_zero(B) == 1) ||
      (s21_matrixes_sizes_is_equal(A, B) == 0)) {
    return_value = FAILURE;
  } else {
    return_value = SUCCESS;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= S21_FLOAT_EPS) {
          return_value = FAILURE;
          i = A->rows;
          j = A->columns;
        }
      }
    }
  }
  return return_value;
}
