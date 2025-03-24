#include "s21_matrix_test.h"

START_TEST(s21_mult_matrix_test_1) {
  matrix_t A_1;
  matrix_t B_1;
  matrix_t result_1;

  ck_assert_int_eq(s21_mult_matrix(NULL, &B_1, &result_1),
                   RETURN_ERROR_INCORRECT_MARIX_1);
  ck_assert_int_eq(s21_mult_matrix(&A_1, NULL, &result_1),
                   RETURN_ERROR_INCORRECT_MARIX_1);
  ck_assert_int_eq(s21_mult_matrix(&A_1, &B_1, NULL),
                   RETURN_ERROR_INCORRECT_MARIX_1);
  ck_assert_int_eq(s21_mult_matrix(&A_1, NULL, NULL),
                   RETURN_ERROR_INCORRECT_MARIX_1);
  ck_assert_int_eq(s21_mult_matrix(NULL, &B_1, NULL),
                   RETURN_ERROR_INCORRECT_MARIX_1);
  ck_assert_int_eq(s21_mult_matrix(NULL, NULL, &result_1),
                   RETURN_ERROR_INCORRECT_MARIX_1);
  ck_assert_int_eq(s21_mult_matrix(NULL, NULL, NULL),
                   RETURN_ERROR_INCORRECT_MARIX_1);

  matrix_t A_2;
  A_2.rows = 0;
  A_2.columns = 1;
  matrix_t B_2;
  B_2.rows = 1;
  B_2.columns = 1;
  matrix_t result_2;
  ck_assert_int_eq(s21_mult_matrix(&A_2, &B_2, &result_2),
                   RETURN_ERROR_INCORRECT_MARIX_1);
}
END_TEST

START_TEST(s21_mult_matrix_test_2) {
  matrix_t A_1;
  A_1.rows = 2;
  A_1.columns = 3;
  matrix_t B_1;
  B_1.rows = 2;
  B_1.columns = 4;
  matrix_t result_1;
  ck_assert_int_eq(s21_mult_matrix(&A_1, &B_1, &result_1),
                   RETURN_CALCULATION_ERROR_2);

  matrix_t A_2;
  s21_create_matrix(2, 3, &A_2);
  matrix_t B_2;
  s21_create_matrix(2, 3, &B_2);
  matrix_t result_2;

  A_2.matrix[0][0] = 1.0;
  A_2.matrix[0][1] = S21_NAN;
  A_2.matrix[0][2] = 3.0;
  A_2.matrix[1][0] = 4.0;
  A_2.matrix[1][1] = 5.0;
  A_2.matrix[1][2] = 6.0;

  B_2.matrix[0][0] = 1.0;
  B_2.matrix[0][1] = 2.0;
  B_2.matrix[0][2] = 3.0;
  B_2.matrix[1][0] = 4.0;
  B_2.matrix[1][1] = 5.0;
  B_2.matrix[1][2] = 6.0;

  ck_assert_int_eq(s21_mult_matrix(&A_2, &B_2, &result_2),
                   RETURN_CALCULATION_ERROR_2);

  A_2.matrix[0][1] = S21_INF_P;
  ck_assert_int_eq(s21_mult_matrix(&A_2, &B_2, &result_2),
                   RETURN_CALCULATION_ERROR_2);

  A_2.matrix[0][1] = S21_INF_N;
  ck_assert_int_eq(s21_mult_matrix(&A_2, &B_2, &result_2),
                   RETURN_CALCULATION_ERROR_2);

  s21_remove_matrix(&A_2);
  s21_remove_matrix(&B_2);

  matrix_t A_3;
  s21_create_matrix(2, 3, &A_3);
  matrix_t B_3;
  s21_create_matrix(2, 3, &B_3);
  matrix_t result_3;

  A_3.matrix[0][0] = 1.0;
  A_3.matrix[0][1] = S21_NAN;
  A_3.matrix[0][2] = 3.0;
  A_3.matrix[1][0] = 4.0;
  A_3.matrix[1][1] = 5.0;
  A_3.matrix[1][2] = 6.0;

  B_3.matrix[0][0] = 1.0;
  B_3.matrix[0][1] = 2.0;
  B_3.matrix[0][2] = 3.0;
  B_3.matrix[1][0] = 4.0;
  B_3.matrix[1][1] = 5.0;
  B_3.matrix[1][2] = 6.0;

  ck_assert_int_eq(s21_mult_matrix(&A_3, &B_3, &result_3),
                   RETURN_CALCULATION_ERROR_2);

  A_3.matrix[0][1] = S21_INF_P;
  ck_assert_int_eq(s21_mult_matrix(&A_3, &B_3, &result_3),
                   RETURN_CALCULATION_ERROR_2);

  A_3.matrix[0][1] = S21_INF_N;
  ck_assert_int_eq(s21_mult_matrix(&A_3, &B_3, &result_3),
                   RETURN_CALCULATION_ERROR_2);

  s21_remove_matrix(&A_3);
  s21_remove_matrix(&B_3);
}
END_TEST

START_TEST(s21_mult_matrix_test_3) {
  matrix_t A_1;
  s21_create_matrix(3, 2, &A_1);
  matrix_t B_1;
  s21_create_matrix(2, 3, &B_1);
  matrix_t result_1;

  A_1.matrix[0][0] = 1.0;
  A_1.matrix[0][1] = 4.0;
  A_1.matrix[1][0] = 2.0;
  A_1.matrix[1][1] = 5.0;
  A_1.matrix[2][0] = 3.0;
  A_1.matrix[2][1] = 6.0;

  B_1.matrix[0][0] = 1.0;
  B_1.matrix[0][1] = -1.0;
  B_1.matrix[0][2] = 1.0;
  B_1.matrix[1][0] = 2.0;
  B_1.matrix[1][1] = 3.0;
  B_1.matrix[1][2] = 4.0;

  ck_assert_int_eq(s21_mult_matrix(&A_1, &B_1, &result_1), RETURN_OK_0);
  ck_assert_int_eq(result_1.rows, 3);
  ck_assert_int_eq(result_1.columns, 3);

  ck_assert_double_eq(result_1.matrix[0][0], 9.0);
  ck_assert_double_eq(result_1.matrix[0][1], 11.0);
  ck_assert_double_eq(result_1.matrix[0][2], 17.0);
  ck_assert_double_eq(result_1.matrix[1][0], 12.0);
  ck_assert_double_eq(result_1.matrix[1][1], 13.0);
  ck_assert_double_eq(result_1.matrix[1][2], 22.0);
  ck_assert_double_eq(result_1.matrix[2][0], 15.0);
  ck_assert_double_eq(result_1.matrix[2][1], 15.0);
  ck_assert_double_eq(result_1.matrix[2][2], 27.0);

  s21_remove_matrix(&A_1);
  s21_remove_matrix(&B_1);
  s21_remove_matrix(&result_1);
}
END_TEST

START_TEST(s21_mult_matrix_test_4) {
  matrix_t A_1;
  s21_create_matrix(2, 3, &A_1);
  matrix_t B_1;
  s21_create_matrix(3, 2, &B_1);
  matrix_t result_1;

  A_1.matrix[0][0] = 1.0;
  A_1.matrix[0][1] = 2.0;
  A_1.matrix[0][2] = 3.0;
  A_1.matrix[1][0] = 4.0;
  A_1.matrix[1][1] = -5.0;
  A_1.matrix[1][2] = 6.0;

  B_1.matrix[0][0] = 1.0;
  B_1.matrix[0][1] = 2.0;
  B_1.matrix[1][0] = 3.0;
  B_1.matrix[1][1] = 4.0;
  B_1.matrix[2][0] = 5.0;
  B_1.matrix[2][1] = 6.0;

  ck_assert_int_eq(s21_mult_matrix(&A_1, &B_1, &result_1), RETURN_OK_0);
  ck_assert_int_eq(result_1.rows, 2);
  ck_assert_int_eq(result_1.columns, 2);

  ck_assert_double_eq(result_1.matrix[0][0], 22.0);
  ck_assert_double_eq(result_1.matrix[0][1], 28.0);
  ck_assert_double_eq(result_1.matrix[1][0], 19.0);
  ck_assert_double_eq(result_1.matrix[1][1], 24.0);

  s21_remove_matrix(&A_1);
  s21_remove_matrix(&B_1);
  s21_remove_matrix(&result_1);
}
END_TEST

START_TEST(s21_mult_matrix_test_5) {
  matrix_t A_1;
  s21_create_matrix(6, 4, &A_1);
  matrix_t B_1;
  s21_create_matrix(4, 3, &B_1);
  matrix_t result_1;

  A_1.matrix[0][0] = 1.0;
  A_1.matrix[0][1] = 2.0;
  A_1.matrix[0][2] = 3.0;
  A_1.matrix[0][3] = 4.0;
  A_1.matrix[1][0] = 5.0;
  A_1.matrix[1][1] = 6.0;
  A_1.matrix[1][2] = 7.0;
  A_1.matrix[1][3] = 8.0;
  A_1.matrix[2][0] = 9.0;
  A_1.matrix[2][1] = 10.0;
  A_1.matrix[2][2] = 11.0;
  A_1.matrix[2][3] = 12.0;
  A_1.matrix[3][0] = 13.0;
  A_1.matrix[3][1] = 14.0;
  A_1.matrix[3][2] = 15.0;
  A_1.matrix[3][3] = 16.0;
  A_1.matrix[4][0] = 17.0;
  A_1.matrix[4][1] = 18.0;
  A_1.matrix[4][2] = 19.0;
  A_1.matrix[4][3] = 20.0;
  A_1.matrix[5][0] = 21.0;
  A_1.matrix[5][1] = 22.0;
  A_1.matrix[5][2] = 23.0;
  A_1.matrix[5][3] = 24.0;

  B_1.matrix[0][0] = 1.0;
  B_1.matrix[0][1] = 2.0;
  B_1.matrix[0][2] = 3.0;
  B_1.matrix[1][0] = 4.0;
  B_1.matrix[1][1] = 5.0;
  B_1.matrix[1][2] = 6.0;
  B_1.matrix[2][0] = 7.0;
  B_1.matrix[2][1] = 8.0;
  B_1.matrix[2][2] = 9.0;
  B_1.matrix[3][0] = 10.0;
  B_1.matrix[3][1] = 11.0;
  B_1.matrix[3][2] = 12.0;

  ck_assert_int_eq(s21_mult_matrix(&A_1, &B_1, &result_1), RETURN_OK_0);
  ck_assert_int_eq(result_1.rows, 6);
  ck_assert_int_eq(result_1.columns, 3);

  ck_assert_double_eq(result_1.matrix[0][0], 70.0);
  ck_assert_double_eq(result_1.matrix[0][1], 80.0);
  ck_assert_double_eq(result_1.matrix[0][2], 90.0);
  ck_assert_double_eq(result_1.matrix[1][0], 158.0);
  ck_assert_double_eq(result_1.matrix[1][1], 184.0);
  ck_assert_double_eq(result_1.matrix[1][2], 210.0);
  ck_assert_double_eq(result_1.matrix[2][0], 246.0);
  ck_assert_double_eq(result_1.matrix[2][1], 288.0);
  ck_assert_double_eq(result_1.matrix[2][2], 330.0);
  ck_assert_double_eq(result_1.matrix[3][0], 334.0);
  ck_assert_double_eq(result_1.matrix[3][1], 392.0);
  ck_assert_double_eq(result_1.matrix[3][2], 450.0);
  ck_assert_double_eq(result_1.matrix[4][0], 422.0);
  ck_assert_double_eq(result_1.matrix[4][1], 496.0);
  ck_assert_double_eq(result_1.matrix[4][2], 570.0);
  ck_assert_double_eq(result_1.matrix[5][0], 510.0);
  ck_assert_double_eq(result_1.matrix[5][1], 600.0);
  ck_assert_double_eq(result_1.matrix[5][2], 690.0);

  s21_remove_matrix(&A_1);
  s21_remove_matrix(&B_1);
  s21_remove_matrix(&result_1);
}
END_TEST

Suite *suite(void) {
  Suite *suite = suite_create("\033[32m s21_mult_matrix_test \033[0m");
  TCase *tcase = tcase_create("core");

  tcase_add_test(tcase, s21_mult_matrix_test_1);
  tcase_add_test(tcase, s21_mult_matrix_test_2);
  tcase_add_test(tcase, s21_mult_matrix_test_3);
  tcase_add_test(tcase, s21_mult_matrix_test_4);
  tcase_add_test(tcase, s21_mult_matrix_test_5);

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