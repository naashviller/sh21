#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int return_value = -1;

  if ((s21_matrix_ptr_is_null(result) == 1) || (rows <= 0) || (columns <= 0)) {
    return_value = RETURN_ERROR_INCORRECT_MARIX_1;
  } else {
    result->matrix = (double **)calloc(rows, sizeof(double *));

    if (result->matrix == NULL) {
      return_value = RETURN_ERROR_INCORRECT_MARIX_1;
    } else {
      result->rows = rows;
      result->columns = columns;

      for (int i = 0; i < rows; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
        if (result->matrix[i] == NULL) {
          return_value = RETURN_ERROR_INCORRECT_MARIX_1;
        }
      }

      if (return_value == RETURN_ERROR_INCORRECT_MARIX_1) {
        s21_remove_matrix(result);
      } else {
        return_value = RETURN_OK_0;
      }
    }
  }
  return return_value;
}
