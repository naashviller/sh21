#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int return_value = -1;

  if ((s21_matrix_ptr_is_null(A) == 1) || (result == NULL) ||
      (s21_matrix_sizes_le_zero(A) == 1)) {
    return_value = RETURN_ERROR_INCORRECT_MARIX_1;
  } else if ((s21_matrix_is_square(A) == 0) ||
             (s21_matrix_element_is_nan_inf(A) == 1)) {
    return_value = RETURN_CALCULATION_ERROR_2;
  } else {
    return_value = RETURN_OK_0;
    *result = s21_determinant_calculation(A, &return_value);
  }

  return return_value;
}
