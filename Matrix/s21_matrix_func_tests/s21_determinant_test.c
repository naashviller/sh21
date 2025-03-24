#include "s21_matrix_test.h"

START_TEST(s21_determinant_test_1) {
  matrix_t A_1;
  double result_1 = 0.0;

  ck_assert_int_eq(s21_determinant(NULL, &result_1),
                   RETURN_ERROR_INCORRECT_MARIX_1);
  ck_assert_int_eq(s21_determinant(&A_1, NULL), RETURN_ERROR_INCORRECT_MARIX_1);
  ck_assert_int_eq(s21_determinant(NULL, NULL), RETURN_ERROR_INCORRECT_MARIX_1);

  matrix_t A_2;
  A_2.rows = 0;
  A_2.columns = 1;
  double result_2 = 0.0;
  ck_assert_int_eq(s21_determinant(&A_2, &result_2),
                   RETURN_ERROR_INCORRECT_MARIX_1);
}
END_TEST

START_TEST(s21_determinant_test_2) {
  matrix_t A_1;
  s21_create_matrix(2, 2, &A_1);
  double result_1 = 0.0;

  A_1.matrix[0][0] = 1.0;
  A_1.matrix[0][1] = 2.0;
  A_1.matrix[1][0] = 3.0;
  A_1.matrix[1][1] = 4.0;

  A_1.matrix[0][1] = S21_NAN;
  ck_assert_int_eq(s21_determinant(&A_1, &result_1),
                   RETURN_CALCULATION_ERROR_2);

  A_1.matrix[0][1] = S21_INF_P;
  ck_assert_int_eq(s21_determinant(&A_1, &result_1),
                   RETURN_CALCULATION_ERROR_2);

  A_1.matrix[0][1] = S21_INF_N;
  ck_assert_int_eq(s21_determinant(&A_1, &result_1),
                   RETURN_CALCULATION_ERROR_2);

  s21_remove_matrix(&A_1);

  matrix_t A_2;
  s21_create_matrix(2, 3, &A_2);
  double result_2 = 0.0;

  ck_assert_int_eq(s21_determinant(&A_2, &result_2),
                   RETURN_CALCULATION_ERROR_2);

  s21_remove_matrix(&A_2);
}
END_TEST

START_TEST(s21_determinant_test_3) {
  matrix_t A_1;
  s21_create_matrix(1, 1, &A_1);
  double result_1 = 0.0;

  A_1.matrix[0][0] = 777.0;

  ck_assert_int_eq(s21_determinant(&A_1, &result_1), RETURN_OK_0);
  ck_assert_double_eq(result_1, 777.0);

  s21_remove_matrix(&A_1);
}
END_TEST

START_TEST(s21_determinant_test_4) {
  matrix_t A_1;
  s21_create_matrix(3, 3, &A_1);
  double result_1 = 0.0;

  A_1.matrix[0][0] = 1.0;
  A_1.matrix[0][1] = 2.0;
  A_1.matrix[0][2] = 3.0;
  A_1.matrix[1][0] = 4.0;
  A_1.matrix[1][1] = 5.0;
  A_1.matrix[1][2] = 6.0;
  A_1.matrix[2][0] = 7.0;
  A_1.matrix[2][1] = 8.0;
  A_1.matrix[2][2] = 9.0;

  ck_assert_int_eq(s21_determinant(&A_1, &result_1), RETURN_OK_0);
  ck_assert_double_eq(result_1, 0.0);

  s21_remove_matrix(&A_1);
}
END_TEST

START_TEST(s21_determinant_test_5) {
  matrix_t A_1;
  s21_create_matrix(3, 3, &A_1);
  double result_1 = 0.0;

  A_1.matrix[0][0] = 3.0;
  A_1.matrix[0][1] = 3.0;
  A_1.matrix[0][2] = 3.0;
  A_1.matrix[1][0] = 2.0;
  A_1.matrix[1][1] = 4.0;
  A_1.matrix[1][2] = 4.0;
  A_1.matrix[2][0] = 1.0;
  A_1.matrix[2][1] = 3.0;
  A_1.matrix[2][2] = 6.0;

  ck_assert_int_eq(s21_determinant(&A_1, &result_1), RETURN_OK_0);
  ck_assert_double_eq(result_1, 18.0);

  s21_remove_matrix(&A_1);
}
END_TEST

START_TEST(s21_determinant_test_6) {
  matrix_t A_1;
  s21_create_matrix(4, 4, &A_1);
  double result_1 = 0.0;

  A_1.matrix[0][0] = 1.0;
  A_1.matrix[0][1] = 134.0;
  A_1.matrix[0][2] = 5.0;
  A_1.matrix[0][3] = 546.0;
  A_1.matrix[1][0] = -18.0;
  A_1.matrix[1][1] = 67.0;
  A_1.matrix[1][2] = 45.0;
  A_1.matrix[1][3] = 0.0;
  A_1.matrix[2][0] = 64.0;
  A_1.matrix[2][1] = -34.0;
  A_1.matrix[2][2] = 78.0;
  A_1.matrix[2][3] = 456.0;
  A_1.matrix[3][0] = 45.0;
  A_1.matrix[3][1] = 8789.0;
  A_1.matrix[3][2] = 45.0;
  A_1.matrix[3][3] = -786.0;

  ck_assert_int_eq(s21_determinant(&A_1, &result_1), RETURN_OK_0);
  ck_assert_double_eq(result_1, -20702460288.0);

  s21_remove_matrix(&A_1);
}
END_TEST

Suite *suite(void) {
  Suite *suite = suite_create("\033[32m s21_determinant_test \033[0m");
  TCase *tcase = tcase_create("core");

  tcase_add_test(tcase, s21_determinant_test_1);
  tcase_add_test(tcase, s21_determinant_test_2);
  tcase_add_test(tcase, s21_determinant_test_3);
  tcase_add_test(tcase, s21_determinant_test_4);
  tcase_add_test(tcase, s21_determinant_test_5);
  tcase_add_test(tcase, s21_determinant_test_6);

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