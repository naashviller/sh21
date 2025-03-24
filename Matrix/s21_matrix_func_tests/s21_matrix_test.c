#include "s21_matrix_test.h"

// s21_matrix_ptr_is_null

START_TEST(s21_matrix_test_1) {
  matrix_t A;

  ck_assert_int_eq(s21_matrix_ptr_is_null(NULL), 1);
  ck_assert_int_eq(s21_matrix_ptr_is_null(&A), 0);
}
END_TEST

// s21_matrix_sizes_le_zero

START_TEST(s21_matrix_test_2) {
  matrix_t A;

  ck_assert_int_eq(s21_matrix_sizes_le_zero(NULL), -1);

  A.rows = 0;
  A.columns = -1;
  ck_assert_int_eq(s21_matrix_sizes_le_zero(&A), 1);
  A.rows = -1;
  A.columns = 0;
  ck_assert_int_eq(s21_matrix_sizes_le_zero(&A), 1);
  A.rows = -1;
  A.columns = -1;
  ck_assert_int_eq(s21_matrix_sizes_le_zero(&A), 1);
  A.rows = 0;
  A.columns = 1;
  ck_assert_int_eq(s21_matrix_sizes_le_zero(&A), 1);
  A.rows = 1;
  A.columns = 0;
  ck_assert_int_eq(s21_matrix_sizes_le_zero(&A), 1);

  A.rows = 1;
  A.columns = 1;
  ck_assert_int_eq(s21_matrix_sizes_le_zero(&A), 0);
}
END_TEST

// s21_matrixes_sizes_is_equal

START_TEST(s21_matrix_test_3) {
  matrix_t A;
  s21_create_matrix(1, 1, &A);
  matrix_t B;
  s21_create_matrix(1, 1, &B);

  ck_assert_int_eq(s21_matrixes_sizes_is_equal(&A, NULL), -1);
  ck_assert_int_eq(s21_matrixes_sizes_is_equal(NULL, &B), -1);
  ck_assert_int_eq(s21_matrixes_sizes_is_equal(NULL, NULL), -1);

  A.rows = 1;
  A.columns = 2;
  B.rows = 1;
  B.columns = 2;
  ck_assert_int_eq(s21_matrixes_sizes_is_equal(&A, &B), 1);

  A.rows = 1;
  A.columns = 2;
  B.rows = -1;
  B.columns = 2;
  ck_assert_int_eq(s21_matrixes_sizes_is_equal(&A, &B), 0);
  A.rows = 1;
  A.columns = 2;
  B.rows = 1;
  B.columns = -2;
  ck_assert_int_eq(s21_matrixes_sizes_is_equal(&A, &B), 0);
  A.rows = 1;
  A.columns = 2;
  B.rows = -1;
  B.columns = -2;
  ck_assert_int_eq(s21_matrixes_sizes_is_equal(&A, &B), 0);

  A.rows = 1;
  A.columns = 1;
  s21_remove_matrix(&A);
  B.rows = 1;
  B.columns = 1;
  s21_remove_matrix(&B);
}
END_TEST

// s21_matrix_element_is_nan_inf

START_TEST(s21_matrix_test_4) {
  matrix_t A;
  s21_create_matrix(2, 3, &A);

  ck_assert_int_eq(s21_matrix_element_is_nan_inf(NULL), -1);

  ck_assert_int_eq(s21_matrix_element_is_nan_inf(&A), 0);

  A.matrix[1][1] = S21_NAN;
  ck_assert_int_eq(s21_matrix_element_is_nan_inf(&A), 1);
  A.matrix[1][1] = S21_INF_P;
  ck_assert_int_eq(s21_matrix_element_is_nan_inf(&A), 1);
  A.matrix[1][1] = S21_INF_N;
  ck_assert_int_eq(s21_matrix_element_is_nan_inf(&A), 1);

  s21_remove_matrix(&A);
}
END_TEST

// s21_double_is_nan_inf

START_TEST(s21_matrix_test_5) {
  double test_var = 0.0;

  test_var = 1.0;
  ck_assert_int_eq(s21_double_is_nan_inf(test_var), 0);

  test_var = S21_NAN;
  ck_assert_int_eq(s21_double_is_nan_inf(test_var), 1);
  test_var = S21_INF_P;
  ck_assert_int_eq(s21_double_is_nan_inf(test_var), 1);
  test_var = S21_INF_N;
  ck_assert_int_eq(s21_double_is_nan_inf(test_var), 1);
}
END_TEST

// s21_matrixes_is_correct_for_mult

START_TEST(s21_matrix_test_6) {
  matrix_t A;
  s21_create_matrix(1, 1, &A);
  matrix_t B;
  s21_create_matrix(1, 1, &B);

  ck_assert_int_eq(s21_matrixes_is_correct_for_mult(&A, NULL), -1);
  ck_assert_int_eq(s21_matrixes_is_correct_for_mult(NULL, &B), -1);
  ck_assert_int_eq(s21_matrixes_is_correct_for_mult(NULL, NULL), -1);

  A.rows = 1;
  A.columns = 2;
  B.rows = 2;
  B.columns = 2;
  ck_assert_int_eq(s21_matrixes_is_correct_for_mult(&A, &B), 1);

  A.rows = 1;
  A.columns = 2;
  B.rows = 1;
  B.columns = 2;
  ck_assert_int_eq(s21_matrixes_is_correct_for_mult(&A, &B), 0);

  A.rows = 1;
  A.columns = 1;
  s21_remove_matrix(&A);
  B.rows = 1;
  B.columns = 1;
  s21_remove_matrix(&B);
}
END_TEST

// s21_matrix_is_square

START_TEST(s21_matrix_test_7) {
  matrix_t A;

  ck_assert_int_eq(s21_matrix_is_square(NULL), -1);

  A.rows = 1;
  A.columns = 1;
  ck_assert_int_eq(s21_matrix_is_square(&A), 1);

  A.rows = 1;
  A.columns = 2;
  ck_assert_int_eq(s21_matrix_is_square(&A), 0);
}
END_TEST

// s21_fill_minor_matrix

START_TEST(s21_matrix_test_8) {
  matrix_t A;
  s21_create_matrix(3, 4, &A);
  matrix_t B;
  s21_create_matrix(2, 3, &B);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[0][3] = 4.0;

  A.matrix[1][0] = 5.0;
  A.matrix[1][1] = 6.0;
  A.matrix[1][2] = 7.0;
  A.matrix[1][3] = 8.0;

  A.matrix[2][0] = 9.0;
  A.matrix[2][1] = 10.0;
  A.matrix[2][2] = 11.0;
  A.matrix[2][3] = 12.0;

  s21_fill_minor_matrix(&A, &B, 0, 0);
  ck_assert_double_eq(B.matrix[0][0], 6.0);
  ck_assert_double_eq(B.matrix[0][1], 7.0);
  ck_assert_double_eq(B.matrix[0][2], 8.0);

  ck_assert_double_eq(B.matrix[1][0], 10.0);
  ck_assert_double_eq(B.matrix[1][1], 11.0);
  ck_assert_double_eq(B.matrix[1][2], 12.0);

  s21_fill_minor_matrix(&A, &B, 2, 0);
  ck_assert_double_eq(B.matrix[0][0], 2.0);
  ck_assert_double_eq(B.matrix[0][1], 3.0);
  ck_assert_double_eq(B.matrix[0][2], 4.0);

  ck_assert_double_eq(B.matrix[1][0], 6.0);
  ck_assert_double_eq(B.matrix[1][1], 7.0);
  ck_assert_double_eq(B.matrix[1][2], 8.0);

  s21_fill_minor_matrix(&A, &B, 0, 3);
  ck_assert_double_eq(B.matrix[0][0], 5.0);
  ck_assert_double_eq(B.matrix[0][1], 6.0);
  ck_assert_double_eq(B.matrix[0][2], 7.0);

  ck_assert_double_eq(B.matrix[1][0], 9.0);
  ck_assert_double_eq(B.matrix[1][1], 10.0);
  ck_assert_double_eq(B.matrix[1][2], 11.0);

  s21_fill_minor_matrix(&A, &B, 2, 3);
  ck_assert_double_eq(B.matrix[0][0], 1.0);
  ck_assert_double_eq(B.matrix[0][1], 2.0);
  ck_assert_double_eq(B.matrix[0][2], 3.0);

  ck_assert_double_eq(B.matrix[1][0], 5.0);
  ck_assert_double_eq(B.matrix[1][1], 6.0);
  ck_assert_double_eq(B.matrix[1][2], 7.0);

  s21_fill_minor_matrix(&A, &B, 1, 2);
  ck_assert_double_eq(B.matrix[0][0], 1.0);
  ck_assert_double_eq(B.matrix[0][1], 2.0);
  ck_assert_double_eq(B.matrix[0][2], 4.0);

  ck_assert_double_eq(B.matrix[1][0], 9.0);
  ck_assert_double_eq(B.matrix[1][1], 10.0);
  ck_assert_double_eq(B.matrix[1][2], 12.0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// s21_determinant_calculation

START_TEST(s21_matrix_test_9) {
  matrix_t A_1;
  s21_create_matrix(1, 1, &A_1);
  double result_1 = 0.0;
  int return_value_1 = 0;

  A_1.matrix[0][0] = 777.0;

  result_1 = s21_determinant_calculation(&A_1, &return_value_1);
  ck_assert_double_eq(result_1, 777.0);

  s21_remove_matrix(&A_1);

  matrix_t A_2;
  s21_create_matrix(3, 3, &A_2);
  double result_2 = 0.0;
  int return_value_2 = 0;

  A_2.matrix[0][0] = 3.0;
  A_2.matrix[0][1] = 3.0;
  A_2.matrix[0][2] = 3.0;
  A_2.matrix[1][0] = 2.0;
  A_2.matrix[1][1] = 4.0;
  A_2.matrix[1][2] = 4.0;
  A_2.matrix[2][0] = 1.0;
  A_2.matrix[2][1] = 3.0;
  A_2.matrix[2][2] = 6.0;

  result_2 = s21_determinant_calculation(&A_2, &return_value_2);
  ck_assert_int_eq(return_value_2, RETURN_OK_0);
  ck_assert_double_eq(result_2, 18.0);

  s21_remove_matrix(&A_2);
}
END_TEST

Suite *suite(void) {
  Suite *suite = suite_create("\033[32m s21_matrix_test \033[0m");
  TCase *tcase = tcase_create("core");

  tcase_add_test(tcase, s21_matrix_test_1);
  tcase_add_test(tcase, s21_matrix_test_2);
  tcase_add_test(tcase, s21_matrix_test_3);
  tcase_add_test(tcase, s21_matrix_test_4);
  tcase_add_test(tcase, s21_matrix_test_5);
  tcase_add_test(tcase, s21_matrix_test_6);
  tcase_add_test(tcase, s21_matrix_test_7);
  tcase_add_test(tcase, s21_matrix_test_8);
  tcase_add_test(tcase, s21_matrix_test_9);

  suite_add_tcase(suite, tcase);
  return suite;
}

void case_test_runner(Suite *suite, int *fail_count) {
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_NORMAL);
  *fail_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
}

int main(void) {
  int fail_count = 0;
  case_test_runner(suite(), &fail_count);

  return fail_count;
}