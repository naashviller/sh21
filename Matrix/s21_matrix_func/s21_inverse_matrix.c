#include "../s21_matrix.h"

void s21_inverse_calculation(matrix_t *A, matrix_t *result, int *return_value);

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int return_value = -1;

  if ((s21_matrix_ptr_is_null(A) == 1) ||
      (s21_matrix_ptr_is_null(result) == 1) ||
      (s21_matrix_sizes_le_zero(A) == 1)) {
    return_value = RETURN_ERROR_INCORRECT_MARIX_1;
  } else if ((s21_matrix_is_square(A) == 0) ||
             (s21_matrix_element_is_nan_inf(A) == 1)) {
    return_value = RETURN_CALCULATION_ERROR_2;
  } else {
    s21_inverse_calculation(A, result, &return_value);
  }
  return return_value;
}

void s21_inverse_calculation(matrix_t *A, matrix_t *result, int *return_value) {
  double determinant = 0.0;
  *return_value = s21_determinant(A, &determinant);
  if (*return_value == RETURN_OK_0) {
    if (fabs(determinant) > S21_FLOAT_EPS) {
      matrix_t complements_matrix;
      matrix_t transpose_matrix;
      *return_value = s21_calc_complements(A, &complements_matrix);
      if (*return_value == RETURN_OK_0) {
        *return_value = s21_transpose(&complements_matrix, &transpose_matrix);
        if (*return_value == RETURN_OK_0) {
          determinant = 1 / determinant;
          *return_value =
              s21_mult_number(&transpose_matrix, determinant, result);

          s21_remove_matrix(&transpose_matrix);
        }
        s21_remove_matrix(&complements_matrix);
      }
    } else {
      *return_value = RETURN_CALCULATION_ERROR_2;
    }
  }

  return;
}