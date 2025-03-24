#include "../s21_matrix.h"

void s21_mult_matrixes(const matrix_t *const A, const matrix_t *const B,
                       const matrix_t *result);

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_value = -1;

  if ((s21_matrix_ptr_is_null(A) == 1) || (s21_matrix_ptr_is_null(B) == 1) ||
      (s21_matrix_ptr_is_null(result) == 1) ||
      (s21_matrix_sizes_le_zero(A) == 1) ||
      (s21_matrix_sizes_le_zero(B) == 1)) {
    return_value = RETURN_ERROR_INCORRECT_MARIX_1;
  } else if ((s21_matrixes_is_correct_for_mult(A, B) == 0) ||
             (s21_matrix_element_is_nan_inf(A) == 1) ||
             (s21_matrix_element_is_nan_inf(B) == 1)) {
    return_value = RETURN_CALCULATION_ERROR_2;
  } else {
    return_value = s21_create_matrix(A->rows, B->columns, result);
    if (return_value == RETURN_OK_0) {
      s21_mult_matrixes(A, B, result);
    }
  }
  return return_value;
}

void s21_mult_matrixes(const matrix_t *const A, const matrix_t *const B,
                       const matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      for (int k = 0; k < A->columns; k++) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }

  return;
}