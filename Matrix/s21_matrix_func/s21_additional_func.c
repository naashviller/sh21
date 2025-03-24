#include "../s21_matrix.h"

int s21_matrix_ptr_is_null(const matrix_t *const A) {
  int return_value = -1;

  if (A == NULL) {
    return_value = 1;
  } else {
    return_value = 0;
  }
  return return_value;
}

int s21_matrix_sizes_le_zero(const matrix_t *const A) {
  int return_value = -1;

  if (s21_matrix_ptr_is_null(A) == 1) {
  } else {
    if ((A->rows <= 0) || (A->columns <= 0)) {
      return_value = 1;
    } else {
      return_value = 0;
    }
  }
  return return_value;
}

int s21_matrixes_sizes_is_equal(const matrix_t *const A,
                                const matrix_t *const B) {
  int return_value = -1;

  if ((s21_matrix_ptr_is_null(A) == 1) || (s21_matrix_ptr_is_null(B) == 1)) {
  } else {
    if ((A->rows == B->rows) && (A->columns == B->columns)) {
      return_value = 1;
    } else {
      return_value = 0;
    }
  }
  return return_value;
}

int s21_matrix_element_is_nan_inf(const matrix_t *const A) {
  int return_value = -1;

  if (s21_matrix_ptr_is_null(A) == 1) {
  } else {
    return_value = 0;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if ((S21_IS_NAN(A->matrix[i][j]) == 1) ||
            (S21_IS_INF_P(A->matrix[i][j]) == 1) ||
            (S21_IS_INF_N(A->matrix[i][j]) == 1)) {
          return_value = 1;
          i = A->rows;
          j = A->columns;
        }
      }
    }
  }
  return return_value;
}

int s21_double_is_nan_inf(double number) {
  int return_value = -1;

  if ((S21_IS_NAN(number) == 1) || (S21_IS_INF_P(number) == 1) ||
      (S21_IS_INF_N(number) == 1)) {
    return_value = 1;
  } else {
    return_value = 0;
  }
  return return_value;
}

int s21_matrixes_is_correct_for_mult(const matrix_t *const A,
                                     const matrix_t *const B) {
  int return_value = -1;

  if ((s21_matrix_ptr_is_null(A) == 1) || (s21_matrix_ptr_is_null(B) == 1)) {
  } else {
    if (A->columns == B->rows) {
      return_value = 1;
    } else {
      return_value = 0;
    }
  }
  return return_value;
}

int s21_matrix_is_square(const matrix_t *const A) {
  int return_value = -1;

  if (s21_matrix_ptr_is_null(A) == 1) {
  } else {
    if (A->rows == A->columns) {
      return_value = 1;
    } else {
      return_value = 0;
    }
  }
  return return_value;
}

void s21_fill_minor_matrix(const matrix_t *const A,
                           const matrix_t *minor_matrix, int minor_row,
                           int minor_column) {
  if ((s21_matrix_ptr_is_null(A) == 1) ||
      (s21_matrix_ptr_is_null(minor_matrix) == 1) || (minor_row < 0) ||
      (minor_row > A->rows) || (minor_column < 0) ||
      (minor_column > A->columns)) {
  } else {
    for (int i = 0, A_i = 0; i < minor_matrix->rows; i++, A_i++) {
      if (A_i == minor_row) {
        A_i++;
      }
      for (int j = 0, A_j = 0; j < minor_matrix->columns; j++, A_j++) {
        if (A_j == minor_column) {
          A_j++;
        }
        minor_matrix->matrix[i][j] = A->matrix[A_i][A_j];
      }
    }
  }
  return;
}

double s21_determinant_calculation(const matrix_t *const A, int *return_value) {
  int return_value_tmp = -1;
  double result = 0.0;

  if (A->rows == 1) {
    result = A->matrix[0][0];
  } else {
    matrix_t minor_matrix;
    for (int i = 0, sign = 1; i < A->columns; i++, sign *= -1) {
      return_value_tmp =
          s21_create_matrix(A->rows - 1, A->columns - 1, &minor_matrix);
      if (return_value_tmp == RETURN_OK_0) {
        s21_fill_minor_matrix(A, &minor_matrix, 0, i);
        result += sign * A->matrix[0][i] *
                  s21_determinant_calculation(&minor_matrix, return_value);
        s21_remove_matrix(&minor_matrix);
      } else {
        *return_value = RETURN_ERROR_INCORRECT_MARIX_1;
      }
    }
  }
  return result;
}