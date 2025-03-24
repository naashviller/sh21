#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1  // Only for s21_eq_matrix
#define FAILURE 0  // Only for s21_eq_matrix

#define RETURN_OK_0 0
#define RETURN_ERROR_INCORRECT_MARIX_1 1
#define RETURN_CALCULATION_ERROR_2 2

#define S21_NAN (0.0) / (0.0)
#define S21_IS_NAN(x) ((x) != (x))
#define S21_INF_P (1.0) / (+0.0)
#define S21_IS_INF_P(x) ((x) == S21_INF_P)
#define S21_INF_N (1.0) / (-0.0)
#define S21_IS_INF_N(x) ((x) == S21_INF_N)

#define S21_FLOAT_EPS 1E-7

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// Additional Functions:
int s21_matrix_ptr_is_null(const matrix_t *const A);
int s21_matrix_sizes_le_zero(const matrix_t *const A);
int s21_matrixes_sizes_is_equal(const matrix_t *const A,
                                const matrix_t *const B);
int s21_matrix_element_is_nan_inf(const matrix_t *const A);
int s21_double_is_nan_inf(double number);
int s21_matrixes_is_correct_for_mult(const matrix_t *const A,
                                     const matrix_t *const B);
int s21_matrix_is_square(const matrix_t *const A);
void s21_fill_minor_matrix(const matrix_t *const A,
                           const matrix_t *minor_matrix, int minor_row,
                           int minor_columns);
double s21_determinant_calculation(const matrix_t *const A, int *return_value);

#endif
