#include "s21_matrix_test.h"

START_TEST(s21_sub_matrix_test_1) {
  matrix_t A_1;
  matrix_t B_1;
  matrix_t result_1;

  ck_assert_int_eq(s21_sub_matrix(NULL, &B_1, &result_1),
                   RETURN_ERROR_INCORRECT_MARIX_1);
  ck_assert_int_eq(s21_sub_matrix(&A_1, NULL, &result_1),
                   RETURN_ERROR_INCORRECT_MARIX_1);
  ck_assert_int_eq(s21_sub_matrix(&A_1, &B_1, NULL),
                   RETURN_ERROR_INCORRECT_MARIX_1);
  ck_assert_int_eq(s21_sub_matrix(&A_1, NULL, NULL),
                   RETURN_ERROR_INCORRECT_MARIX_1);
  ck_assert_int_eq(s21_sub_matrix(NULL, &B_1, NULL),
                   RETURN_ERROR_INCORRECT_MARIX_1);
  ck_assert_int_eq(s21_sub_matrix(NULL, NULL, &result_1),
                   RETURN_ERROR_INCORRECT_MARIX_1);
  ck_assert_int_eq(s21_sub_matrix(NULL, NULL, NULL),
                   RETURN_ERROR_INCORRECT_MARIX_1);

  matrix_t A_2;
  A_2.rows = 0;
  A_2.columns = 1;
  matrix_t B_2;
  B_2.rows = 1;
  B_2.columns = 1;
  matrix_t result_2;
  ck_assert_int_eq(s21_sub_matrix(&A_2, &B_2, &result_2),
                   RETURN_ERROR_INCORRECT_MARIX_1);
}
END_TEST

START_TEST(s21_sub_matrix_test_2) {
  matrix_t A_1;
  A_1.rows = 2;
  A_1.columns = 3;
  matrix_t B_1;
  B_1.rows = 2;
  B_1.columns = 4;
  matrix_t result_1;
  ck_assert_int_eq(s21_sub_matrix(&A_1, &B_1, &result_1),
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

  ck_assert_int_eq(s21_sub_matrix(&A_2, &B_2, &result_2),
                   RETURN_CALCULATION_ERROR_2);

  A_2.matrix[0][1] = S21_INF_P;
  ck_assert_int_eq(s21_sub_matrix(&A_2, &B_2, &result_2),
                   RETURN_CALCULATION_ERROR_2);

  A_2.matrix[0][1] = S21_INF_N;
  ck_assert_int_eq(s21_sub_matrix(&A_2, &B_2, &result_2),
                   RETURN_CALCULATION_ERROR_2);

  s21_remove_matrix(&A_2);
  s21_remove_matrix(&B_2);
}
END_TEST

START_TEST(s21_sub_matrix_test_3) {
  matrix_t A_1;
  s21_create_matrix(2, 3, &A_1);
  matrix_t B_1;
  s21_create_matrix(2, 3, &B_1);
  matrix_t result_1;

  A_1.matrix[0][0] = 1.0;
  A_1.matrix[0][1] = 2.0;
  A_1.matrix[0][2] = 3.0;
  A_1.matrix[1][0] = 4.0;
  A_1.matrix[1][1] = 5.0;
  A_1.matrix[1][2] = 6.0;

  B_1.matrix[0][0] = 1.0;
  B_1.matrix[0][1] = 2.0;
  B_1.matrix[0][2] = 3.0;
  B_1.matrix[1][0] = 4.0;
  B_1.matrix[1][1] = 5.0;
  B_1.matrix[1][2] = 6.0;

  ck_assert_int_eq(s21_sub_matrix(&A_1, &B_1, &result_1), RETURN_OK_0);

  ck_assert_double_eq(result_1.matrix[0][0], 0.0);
  ck_assert_double_eq(result_1.matrix[0][1], 0.0);
  ck_assert_double_eq(result_1.matrix[0][2], 0.0);
  ck_assert_double_eq(result_1.matrix[1][0], 0.0);
  ck_assert_double_eq(result_1.matrix[1][1], 0.0);
  ck_assert_double_eq(result_1.matrix[1][2], 0.0);

  s21_remove_matrix(&A_1);
  s21_remove_matrix(&B_1);
  s21_remove_matrix(&result_1);
}
END_TEST

Suite *suite(void) {
  Suite *suite = suite_create("\033[32m s21_sub_matrix_test \033[0m");
  TCase *tcase = tcase_create("core");

  tcase_add_test(tcase, s21_sub_matrix_test_1);
  tcase_add_test(tcase, s21_sub_matrix_test_2);
  tcase_add_test(tcase, s21_sub_matrix_test_3);

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