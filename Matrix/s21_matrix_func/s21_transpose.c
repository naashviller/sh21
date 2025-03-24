#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int return_value = -1;

  if ((s21_matrix_ptr_is_null(A) == 1) ||
      (s21_matrix_ptr_is_null(result) == 1) ||
      (s21_matrix_sizes_le_zero(A) == 1)) {
    return_value = RETURN_ERROR_INCORRECT_MARIX_1;
  } else {
    return_value = s21_create_matrix(A->columns, A->rows, result);
    if (return_value == RETURN_OK_0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[j][i] = A->matrix[i][j];
        }
      }
    }
  }
  return return_value;
}
