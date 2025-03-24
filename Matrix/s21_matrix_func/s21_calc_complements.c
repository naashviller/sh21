#include "../s21_matrix.h"

void s21_complements_calculation(const matrix_t *const A,
                                 const matrix_t *result, int *return_value);

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int return_value = -1;

  if ((s21_matrix_ptr_is_null(A) == 1) ||
      (s21_matrix_ptr_is_null(result) == 1) ||
      (s21_matrix_sizes_le_zero(A) == 1)) {
    return_value = RETURN_ERROR_INCORRECT_MARIX_1;
  } else if ((s21_matrix_is_square(A) == 0) ||
             (s21_matrix_element_is_nan_inf(A) == 1)) {
    return_value = RETURN_CALCULATION_ERROR_2;
  } else {
    return_value = s21_create_matrix(A->rows, A->columns, result);
    if (return_value == RETURN_OK_0) {
      s21_complements_calculation(A, result, &return_value);
    }
  }
  return return_value;
}

void s21_complements_calculation(const matrix_t *const A,
                                 const matrix_t *result, int *return_value) {
  if (A->rows > 1) {
    matrix_t minor_matrix;
    *return_value =
        s21_create_matrix(A->rows - 1, A->columns - 1, &minor_matrix);
    if (*return_value == RETURN_OK_0) {
      int sign = 1;
      *return_value = RETURN_OK_0;
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          s21_fill_minor_matrix(A, &minor_matrix, i, j);
          sign = ((i + j) % 2 == 0) ? (+1) : (-1);
          result->matrix[i][j] =
              sign * s21_determinant_calculation(&minor_matrix, return_value);
        }
      }
      s21_remove_matrix(&minor_matrix);
    }
  } else {
    result->matrix[0][0] = 1.0;
  }
  return;
}