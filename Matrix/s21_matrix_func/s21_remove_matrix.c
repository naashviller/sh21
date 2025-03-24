#include "../s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  if ((s21_matrix_ptr_is_null(A) == 0) && (A->rows > 0)) {
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i] != NULL) {
        free(A->matrix[i]);
        A->matrix[i] = NULL;
      }
    }
    free(A->matrix);
    A->matrix = NULL;
    A->rows = 0;
    A->columns = 0;
  }

  return;
}
