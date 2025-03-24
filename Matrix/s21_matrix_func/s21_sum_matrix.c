#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_value = -1;

  if ((s21_matrix_ptr_is_null(A) == 1) || (s21_matrix_ptr_is_null(B) == 1) ||
      (s21_matrix_ptr_is_null(result) == 1) ||
      (s21_matrix_sizes_le_zero(A) == 1) ||
      (s21_matrix_sizes_le_zero(B) == 1)) {
    return_value = RETURN_ERROR_INCORRECT_MARIX_1;
  } else if ((s21_matrixes_sizes_is_equal(A, B) == 0) ||
             (s21_matrix_element_is_nan_inf(A) == 1) ||
             (s21_matrix_element_is_nan_inf(B) == 1)) {
    return_value = RETURN_CALCULATION_ERROR_2;
  } else {
    return_value = s21_create_matrix(A->rows, A->columns, result);
    if (return_value == RETURN_OK_0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }
    }
  }
  return return_value;
}
